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

    int j = 0;

    bool won = false;


    try
    {
        while (myWindow->isOpen())
        {
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
                    //sf::Vector2i position = sf::Mouse::getPosition(*myWindow);
                    int xpressed = event.mouseButton.x;
                    int ypressed = event.mouseButton.y;


                    //Byggnation Catapult_tower
                    if (myShop.is_Catapult_button(xpressed, ypressed))
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
                        if(myBoard->exist(towerplacement) == false)
                        {
                            Tower* myTower = new Catapult_tower(towerplacement, myBoard);
                            myBoard->set_Tower(myTower);
                            Controller::controller.change_gold(-10);
                        }
                        can_buy_catapult=false;
                    }


                    //Byggnation av Shooting_tower
                    else if(myShop.is_Shooting_button(xpressed, ypressed))
                    {
                        if(Controller::controller.gold_check(-20) == true) //Kontroll och kostnad shooting
                        {
                            can_buy_shooting = true;
                        }
                    }
                    else if (can_buy_shooting == true)
                    {
                        pos towerplacement;
                        towerplacement.x_pos = event.mouseButton.x;
                        towerplacement.y_pos = event.mouseButton.y;
                        if(myBoard->exist(towerplacement) == false)
                        {
                            Tower* myTower = new Shooting_tower(towerplacement, myBoard);
                            myBoard->set_Tower(myTower);
                            Controller::controller.change_gold(-20);
                        }
                        can_buy_shooting=false;
                    }

                    //New wave
                    else if(myShop.is_wave_button(xpressed, ypressed))
                    {
                        cerr<<"Ny våg"<< endl;
                        //myGame.new_wave();
                    }

                    //Start
                    else if(myShop.is_start_button(xpressed, ypressed))
                    {
                        cerr<<"Start"<< endl;
                    }

                    //Stopp
                    else if(myShop.is_stop_button(xpressed, ypressed))
                    {
                        cerr<<"Stop"<< endl;
                    }

                }
                }



            }




            

            if(!myGame.shall_feed and (sf::Keyboard::isKeyPressed(sf::Keyboard::N)))
            {
                myGame.new_wave();
            }

            if(myGame.shall_feed == true)
            {
                myGame.feed_Sheep(myClock.getElapsedTime().asSeconds()*50);
                
                    if(myGame.shall_feed == true)
                {
                    myGame.feed_Sheep(myClock.getElapsedTime().asSeconds()*50);
                }
                myGame.update_Game(myClock.getElapsedTime().asSeconds()*50);
                myClock.restart();
                myGame.update_background_graphics();
                myGame.update_foreground_graphics();
                myShop.update_scoreboard();
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
                    myGame.ending = true;
                }

                myWindow->display();
                myWindow->clear();
                if (tiden > 0)
                {
                    j = j + 1;
                    std::cout << j << std::endl;
                    tiden = tiden - myClock.getElapsedTime().asSeconds();
                }
                else
                {
                    tiden = 1;
                    j = 0;
                }
               
            }





            myGame.update_Game(myClock.getElapsedTime().asSeconds()*50);
            myClock.restart();
            myGame.update_background_graphics();
            myGame.update_foreground_graphics();
            myShop.update_scoreboard();
            myWindow->display();
            myWindow->clear();
            tiden = tiden - myClock.getElapsedTime().asSeconds();


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
