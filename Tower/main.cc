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



int main()
{
    sf::RenderWindow* myWindow = new sf::RenderWindow(sf::VideoMode(800,600), "Who let the sheep out?");
    Course myCourse;
    Board* myBoard = new Board(myCourse);
    Game myGame(myWindow, myBoard);
    Shop myShop(myBoard, myWindow);
    sf::Clock myClock;
    float tiden = 1;
    int i = 0;
    sf::Event event;
    int tower_width = 50;
    myWindow->setFramerateLimit(60);
    sf::IntRect mainframe(0,0,600,600);

    bool can_buy_catapult = false;
    bool can_buy_shooting = false;

    std::string name;

    sf::Font arial;
    arial.loadFromFile("arial.ttf");

    sf::Music myMusic;
    myMusic.openFromFile("Harvest_Moon_Music_-_Harvest_Festival.wav");
    myMusic.setLoop(true);
    myMusic.setVolume(20);
    myMusic.play();

    sf::Music hej;
    hej.openFromFile("cartoon004.wav");
    hej.setLoop(false);

    sf::Music hejsan;
    hejsan.openFromFile("cartoon011.wav");
    hejsan.setLoop(false);

    bool won = false;


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
                        if(Controller::controller.gold_check(-10) == true) //Kostnad, catapult tower
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
                            Controller::controller.change_gold(-10);
                        }
                        can_buy_catapult=false;
                    }
                    //Byggnation av Shooting_tower
                    else if(myShop.is_Shooting_button(xpressed, ypressed) and myGame.is_shopping() and myGame.is_running())
                    {
                        if(Controller::controller.gold_check(-10) == true) //Kontroll och kostnad shooting
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
                            Controller::controller.change_gold(-20);
                        }
                        can_buy_shooting=false;
                    }
                    //New wave
                    else if(myShop.is_wave_button(xpressed, ypressed) and myGame.is_shopping())
                    {
                        cerr<<"Ny våg"<< endl;
                        myGame.change_shopping(false);
                        myGame.new_wave();
                    }
                    //Start
                    else if(myShop.is_start_button(xpressed, ypressed))
                    {
                        cerr<<"Start"<< endl;
                        myGame.change_run(true);
                        myClock.restart();
                        myMusic.play();
                    }

                    //Stopp
                    else if(myShop.is_stop_button(xpressed, ypressed))
                    {
                        cerr<<"Stop"<< endl;
                        myGame.change_run(false);
                        myMusic.pause();
                    }
                }
                }
            }

            //Här börjar spelkoden
            //Mata får?
            if(myGame.is_running())
            {
                if(myGame.shall_feed == true)
                {
                    myGame.feed_Sheep(myClock.getElapsedTime().asSeconds()*50);
                }

                myGame.update_Game(myClock.getElapsedTime().asSeconds()*50);

                if (myGame.is_sound1())
                {
                    hej.play();
                    myGame.set_sound1(false);
                }
                if (myGame.is_sound2())
                {
                    hejsan.play();
                    myGame.set_sound2(false);
                }

                myClock.restart();
                myGame.update_background_graphics();
                myGame.update_foreground_graphics();
                myShop.update_scoreboard();

                //Har vi vunnit/förlorat
                if ((Controller::controller.get_lives() <= 0) or (myGame.ending))
                {
                    if (!myGame.ending)
                    {
                        sf::Text medelande("Skriv in ditt namn i terminalen: ", arial);
                        medelande.setPosition(170,20);
                        medelande.setColor(sf::Color::Black);
                        myWindow->draw(medelande);
                        myWindow->display();
                        std::cin >> name;
                    }
                    else if(Controller::controller.get_lives() > 0 and !won)
                    {
                        sf::Text medelande("Skriv in ditt namn i terminalen: ", arial);
                        medelande.setPosition(170,20);
                        medelande.setColor(sf::Color::Black);
                        myWindow->draw(medelande);
                        myWindow->display();
                        std::cin >> name;
                        won = true;
                    }
                    myGame.game_over(name);
                    myGame.change_shopping(false);
                    myGame.ending = true;
                }

                myWindow->display();
                myWindow->clear();
                tiden = tiden - myClock.getElapsedTime().asSeconds();
            }

        }
    }
    catch(const exception& e)
    {
        std::cout << "nu är det slut" << std::endl;
        /* myBoard->get_Sheep().clear();
         myBoard->get_Tower().clear();
         myBoard->get_Shot().clear();
         delete myWindow;
         delete myBoard;*/

    }
    return 0;
}
