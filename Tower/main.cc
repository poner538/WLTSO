/*
 * FILNAMN:       main.cc
 * PROGRAMMERARE: Daniel Brattgård 900926-3394, Y3a
 *                Marie Ekbrant 890401-2740, Y3a
 * DATUM:         2013-12-09
 *
 * BESKRIVNING
 *
 * Hur fåren ska flytta sig under spelet
 */

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Game.h"
#include "Course.h"
#include "Shop.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <sstream>


struct User
{
    int  user_score = 0;
    std::string user_name;
};

void set_High_Score(string name, int score)
{
    std::vector<User> score_list;
    std::ifstream Readfile;
    Readfile.open("High_Score.txt");

    if (Readfile.is_open())
    {
        std::string tempname;
        int tempscore;

        while (Readfile >> tempname >> tempscore)
        {
            User temp_user;
            temp_user.user_score = tempscore;
            temp_user.user_name = tempname;
            score_list.push_back(temp_user);

        }
    }
    Readfile.close();
    User new_user;
    new_user.user_score = score;
    new_user.user_name = name;
    for(int i = 0; i < score_list.size(); i++)
    {
        if(score_list.at(i).user_score < score)
        {
            score_list.insert (score_list.begin() + i, new_user);
            i = score_list.size();
        }
    }
    if (score_list.empty())
    {
        score_list.push_back(new_user);
    }
    if(score_list.size() > 10)
    {
        score_list.pop_back();
    }
    std::ofstream Writefile;
    Writefile.open("High_Score.txt");
    for(int i = 0 ; i < score_list.size(); i++)
    {
        Writefile << score_list.at(i).user_name << " " << score_list.at(i).user_score << endl;
    }
    Writefile.close();
}







int main()
{
    sf::RenderWindow* myWindow = new sf::RenderWindow(sf::VideoMode(800,600), "Who let the sheep out?");
    myWindow->setFramerateLimit(60);
    Course myCourse;
    Board* myBoard = new Board(myCourse);
    Game myGame(myWindow, myBoard);
    Shop myShop(myBoard, myWindow);
    sf::Clock myClock;
    sf::Event event;

    bool can_buy_catapult = false;
    bool can_buy_shooting = false;
    bool won = false;
    int tower_width = 50;
    std::string name;
    int level = 0;

    sf::Font arial;
    arial.loadFromFile("arial.ttf");

    sf::Music myMusic;
    myMusic.openFromFile("Harvest_Moon_Music_-_Harvest_Festival.wav");
    myMusic.setLoop(true);
    myMusic.setVolume(20);
    myMusic.play();

    sf::Music hej;
    hej.openFromFile("cartoon013.wav");
    hej.setLoop(false);

    sf::Music san;
    san.openFromFile("cartoon004.wav");
    san.setLoop(false);

    try
    {
        while (myWindow->isOpen())
        {
            //Alla events
            while(myWindow->pollEvent(event))
            {
                switch(event.type)
                {
                case sf::Event::Closed:
                {
                    myWindow->close();
                    break;
                }
                case event.MouseButtonPressed:
                {
                    int xpressed = event.mouseButton.x;
                    int ypressed = event.mouseButton.y;
                    //Byggnation Catapult_tower
                    if (myShop.is_Catapult_button(xpressed, ypressed) and myGame.is_shopping() and myGame.is_running())
                    {
                        if(Controller::controller.gold_check(-70) == true) //Kostnad, catapult tower
                        {
                            can_buy_catapult = true;
                        }
                    }
                    else if (can_buy_catapult == true)
                    {
                        pos towerplacement;
                        towerplacement.x_pos = event.mouseButton.x;
                        towerplacement.y_pos = event.mouseButton.y;
                        int xplus = towerplacement.x_pos + tower_width;
                        int yplus = towerplacement.y_pos + tower_width;
                        if((!myBoard->exist(towerplacement)) and (!myBoard->exist(pos {xplus, towerplacement.y_pos})) and (!myBoard->exist(pos {towerplacement.x_pos, yplus})) and (!myBoard->exist(pos {xplus,yplus})))
                        {
                            Tower* myTower = new Catapult_tower(towerplacement, myBoard);
                            myBoard->set_Tower(myTower);
                            Controller::controller.change_gold(-70);
                        }
                        can_buy_catapult=false;
                    }

                    //Byggnation av Shooting_tower
                    else if(myShop.is_Shooting_button(xpressed, ypressed) and myGame.is_shopping() and myGame.is_running())
                    {
                        if(Controller::controller.gold_check(-50) == true) //Kontroll och kostnad shooting
                        {
                            can_buy_shooting = true;
                        }
                    }
                    else if (can_buy_shooting == true)
                    {
                        pos towerplacement;
                        towerplacement.x_pos = event.mouseButton.x;
                        towerplacement.y_pos = event.mouseButton.y;
                        int xplus = towerplacement.x_pos + tower_width;
                        int yplus = towerplacement.y_pos + tower_width;
                        if((!myBoard->exist(towerplacement)) and (!myBoard->exist(pos {xplus, towerplacement.y_pos})) and (!myBoard->exist(pos {towerplacement.x_pos, yplus})) and (!myBoard->exist(pos {xplus,yplus})))
                        {
                            Tower* myTower = new Shooting_tower(towerplacement, myBoard);
                            myBoard->set_Tower(myTower);
                            Controller::controller.change_gold(-50);
                            can_buy_shooting=false;
                        }
                    }

                    //New wave
                    else if(myShop.is_wave_button(xpressed, ypressed) and myGame.is_shopping())
                    {
                        myGame.change_shopping(false);
                        myGame.new_wave();
                        level = level + 1;
                    }

                    //Start
                    else if(myShop.is_start_button(xpressed, ypressed))
                    {
                        myGame.change_run(true);
                        myClock.restart();
                        myMusic.play();
                    }

                    //Stopp
                    else if(myShop.is_stop_button(xpressed, ypressed))
                    {
                        myGame.change_run(false);
                        myMusic.pause();
                    }

                    else if(myShop.is_volume_minus_button(xpressed, ypressed))
                    {
                        if(myMusic.getVolume()<=20)
                        {
                            myMusic.setVolume(0);
                        }
                        else
                        {
                            myMusic.setVolume(myMusic.getVolume() - 20);
                        }
                    }

                    else if(myShop.is_volume_plus_button(xpressed, ypressed))
                    {
                        if(myMusic.getVolume()>=80)
                        {
                            myMusic.setVolume(100);
                        }
                        else
                        {
                            myMusic.setVolume(myMusic.getVolume() + 20);
                        }
                    }
                }
                }
            }

            //Här börjar spelkoden
            if(myGame.is_running())
            {
                if(myGame.shall_feed == true)
                {
                    myGame.feed_Sheep(myClock.getElapsedTime().asSeconds());
                }

                myGame.update_Game(myClock.getElapsedTime().asSeconds());

                if (myGame.is_sound2())
                {
                    san.play();
                    myGame.set_sound2(false);
                }
                if (myGame.is_sound1())
                {
                    hej.play();
                    myGame.set_sound1(false);
                }

                myClock.restart();
                myGame.update_background_graphics();
                myGame.update_foreground_graphics();
                myShop.update_scoreboard();

                std::ostringstream result4;
                result4 << level;
                std::string tvan4 = result4.str();
                sf::Text lev {tvan4, arial};
                lev.setPosition(570,10);
                lev.setColor(sf::Color::Black);
                myWindow->draw(lev);




                //Har vi vunnit/förlorat
                if ((Controller::controller.get_lives() <= 0) or (myGame.ending))
                {
                    if (!myGame.ending)
                    {
                        sf::Text medelande("Skriv in ditt namn i terminalen: ", arial);
                        medelande.setPosition(170,40);
                        medelande.setColor(sf::Color::Black);
                        myWindow->draw(medelande);
                        myWindow->display();
                        std::cin >> name;
                        myClock.restart();
                        set_High_Score(name, Controller::controller.get_points());
                    }
                    else if(Controller::controller.get_lives() > 0 and !won)
                    {
                        sf::Text medelande("Skriv in ditt namn i terminalen: ", arial);
                        medelande.setPosition(170,40);
                        medelande.setColor(sf::Color::Black);
                        myWindow->draw(medelande);
                        myWindow->display();
                        std::cin >> name;
                        won = true;
                        set_High_Score(name, Controller::controller.get_points());

                    }
                    myGame.game_over(name);
                    myGame.change_shopping(false);
                    myGame.ending = true;
                }
                myWindow->display();
                myWindow->clear();
            }

        }
    }
    catch(const exception& e)
    {
        std::cout << "Error, spelet avslutas!" << std::endl;
        myBoard->get_Sheep().clear();
        myBoard->get_Tower().clear();
        myBoard->get_Shot().clear();
        delete myWindow;
        delete myBoard;

    }
    return 0;
}






