/*
* FILNAMN:          main.cc
* PROGRAMMERARE:    Johanna Laidla      910712-5826, Y3a
                    Ema Becirovic       920510-6249, Y3a
                    Karin Lockowandt    910213-3260, Yi3
                    Daniel Brattg�rd    900926-3394, Y3a
                    Pontus Erlesand     910117-1172, Y3a
                    Marie Ekbrant       890401-2740, Y3a
* DATUM:            2013-12-19
 *
 * BESKRIVNING
 *
 * Main inneh�ller en mainfunktion som styr spelet.
 *
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
#include <iomanip>

//strukt som anv�nds f�r att l�gga till namn och po�ng till highscore.
struct User
{
    int  user_score = 0;
    std::string user_name;
};

//funktion f�r att l�gga till nya namn och score i highscore.
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
    score_list.push_back(new_user);
    for(int i = 0; i < score_list.size(); i++)
    {
        if(score_list.at(i).user_score < score)
        {
            score_list.insert (score_list.begin() + i, new_user);
            i = score_list.size();
            score_list.pop_back();
        }

    }
    if(score_list.size() > 10)
    {
        score_list.pop_back();
    }
    std::ofstream Writefile;
    Writefile.open("High_Score.txt");
    cout << setw(50) << "High Score List:" << endl;
    for(int i = 0 ; i < score_list.size(); i++)
    {
        Writefile << score_list.at(i).user_name << " " << score_list.at(i).user_score << endl;
        std::cout << setw(50) << score_list.at(i).user_name << " " << score_list.at(i).user_score << endl;
    }
    Writefile.close();
}

int main()
{
    //Initiering av variabler
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

    sf::Music shot_sound;
    shot_sound.openFromFile("cartoon013.wav");
    shot_sound.setLoop(false);

    sf::Music death_sound;
    death_sound.openFromFile("cartoon004.wav");
    death_sound.setLoop(false);


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
                    else if (can_buy_catapult)
                    {
                        pos towerplacement;
                        towerplacement.x_pos = event.mouseButton.x;
                        towerplacement.y_pos = event.mouseButton.y;
                        int xplus = towerplacement.x_pos + tower_width;
                        int yplus = towerplacement.y_pos + tower_width;
                        //F�r alla tornens h�rn placeras
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
                        //F�r alla tornens h�rn placeras?
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

            //H�r b�rjar spelkoden
            if(myGame.is_running())
            {
                //Om spelet till�ter att f�r ska matas ska detta g�ras
                if(myGame.is_feeed())
                {
                    myGame.feed_Sheep(myClock.getElapsedTime().asSeconds());
                }
                //Uppdatera spelen genom uppdateringsloopen
                myGame.update_Game(myClock.getElapsedTime().asSeconds());
                //Ljudeffekter spelas upp
                if (myGame.is_sound2())
                {
                    death_sound.play();
                    myGame.set_sound2(false);
                }
                if (myGame.is_sound1())
                {
                    shot_sound.play();
                    myGame.set_sound1(false);
                }
                //F�r att f� ett korrekt tidsv�rde n�sta g�ng spelet uppdateras s� startar klockan om
                myClock.restart();
                myGame.update_background_graphics();
                myGame.update_foreground_graphics();
                myShop.update_scoreboard();

                //h�r skriver vi ut vilken niv� som anv�ndaren kommit till.
                std::ostringstream lvl_stream;
                lvl_stream << level;
                std::string lvl_text = lvl_stream.str();
                sf::Text lev {lvl_text, arial};
                lev.setPosition(570,10);
                lev.setColor(sf::Color::Black);
                myWindow->draw(lev);




                //Har vi vunnit/f�rlorat
                if ((Controller::controller.get_lives() <= 0) or (myGame.is_ending()))
                {
                    if (!myGame.is_ending())
                    {
                        sf::Text term_message("Write your name in the terminal: ", arial);
                        term_message.setPosition(170,40);
                        term_message.setColor(sf::Color::Black);
                        myWindow->draw(term_message);
                        myWindow->display();
                        std::cin >> name;
                        myClock.restart();
                        set_High_Score(name, Controller::controller.get_points());
                    }
                    else if(Controller::controller.get_lives() > 0 and !won)
                    {
                        sf::Text term_message("Write your name in the terminal: ", arial);
                        term_message.setPosition(170,40);
                        term_message.setColor(sf::Color::Black);
                        myWindow->draw(term_message);
                        myWindow->display();
                        std::cin >> name;
                        won = true;
                        set_High_Score(name, Controller::controller.get_points());

                    }
                    myGame.game_over(name);
                    myGame.change_shopping(false);
                    myGame.change_ending(true);
                }
                myWindow->display();
                //Cleara f�nstret efter varje uppdatering
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






