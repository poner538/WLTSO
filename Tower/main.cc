/*
 * FILNAMN:       main.cc
 * PROGRAMMERARE: Daniel Brattg�rd 900926-3394, Y3a
 *                Marie Ekbrant 890401-2740, Y3a
 * DATUM:         2013-12-09
 *
 * BESKRIVNING
 *
 * Hur f�ren ska flytta sig under spelet
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
    float tiden = 20;
    int i = 0;
    sf::Event event;
    int tower_width = 50;
    try
    {

        while (myWindow->isOpen())
        {
            /*if (!myGame.shall_feed)//denna ifsatsen funkar inte av n�gon anledning
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    sf::Vector2i position = sf::Mouse::getPosition(*myWindow);
                    int xpress = position.x;
                    int ypress = position.y;
                    if (myShop.is_wave_button(xpress, ypress));
                    {
                        myGame.new_wave();
                    }
                }
            }*/

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i position = sf::Mouse::getPosition(*myWindow);
                //if ( 650 > position.x > 750 and 50 > position.y > 100 )
                {
                    std::cout << "Du tryckte!" << std::endl;
                    int xtorn = position.x;
                    int ytorn = position.y;
                    int xplus = xtorn + tower_width;
                    int yplus = ytorn + tower_width;

                    if(!myBoard->exist(pos {xtorn,ytorn}) and (!myBoard->exist(pos {xplus,ytorn})) and (!myBoard->exist(pos {xtorn,yplus})) and (!myBoard->exist(pos {xplus,yplus})))
                    {
                        std::cout << "ja" << std::endl;
                        pos Towerpos {xtorn, ytorn};
                        Tower* myTower = new Catapult_tower(Towerpos, myBoard);
                        myBoard->set_Tower(myTower);
                    }

                    else
                    {
                        std::cout << "Nej det f�r du inte!" << std::endl;
                    }
                }
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i position = sf::Mouse::getPosition(*myWindow);
               // if ( 650 > position.x > 750 and 150 > position.y > 200 )
                {
                    std::cout << "Du tryckte!" << std::endl;
                    int xtorn = position.x;
                    int ytorn = position.y;
                    int xplus = xtorn + tower_width;
                    int yplus = ytorn + tower_width;

                    if(!myBoard->exist(pos {xtorn,ytorn}) and (!myBoard->exist(pos {xplus,ytorn})) and (!myBoard->exist(pos {xtorn,yplus})) and (!myBoard->exist(pos {xplus,yplus})))
                    {
                        std::cout << "ja" << std::endl;
                        pos Towerpos {xtorn, ytorn};
                        Tower* myTower = new Shooting_tower(Towerpos, myBoard);
                        myBoard->set_Tower(myTower);
                    }

                    else
                    {
                        std::cout << "Nej det f�r du inte!" << std::endl;
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
        std::cout << "nu �r det slut" << std::endl;
        /* myBoard->get_Sheep().clear();
         myBoard->get_Tower().clear();
         myBoard->get_Shot().clear();
         delete myWindow;
         delete myBoard;*/

    }
    return 0;
}
