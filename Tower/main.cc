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
#include <iostream>
#include <string>
#include <sstream>

int main()
{
    sf::RenderWindow* myWindow = new sf::RenderWindow(sf::VideoMode(800,600), "Who let the sheep out?");
    Course myCourse;
    Board* myBoard = new Board(myCourse);
    Game myGame(myWindow, myBoard);
    sf::Clock myClock;
    float tiden = 20;
    int i = 0;
    sf::Event event;
    int tower_width = 50;
    try
    {

        while (tiden > 0)
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i position = sf::Mouse::getPosition(*myWindow);

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
                    std::cout << "Nej det får du inte!" << std::endl;
                }
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                sf::Vector2i position = sf::Mouse::getPosition(*myWindow);

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
                    std::cout << "Nej det får du inte!" << std::endl;
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



            //std::string tvan;
            std::ostringstream result;
            result << Controller::controller.get_lives();
            std::string tvan = result.str();
            std::string ettan = "Antal liv: ";
            ettan = ettan + tvan;
            sf::Font arial;
            arial.loadFromFile("arial.ttf");
            sf::Text liv{ettan, arial};
            liv.setPosition(200,200);
            myWindow->draw(liv);

            std::ostringstream result2;
            result2 << Controller::controller.get_gold();
            std::string tvan2 = result2.str();
            ettan = "Guld: ";
            ettan = ettan+ tvan2;
            sf::Text guld{ettan, arial};
            guld.setPosition(200,230);
            myWindow->draw(guld);

            std::ostringstream result3;
            result3 << Controller::controller.get_points();
            std::string tvan3 = result3.str();
            ettan = "Poäng: ";
            ettan = ettan + tvan3;
            sf::Text p{ettan, arial};
            p.setPosition(200,260);
            myWindow->draw(p);


            myWindow->display();
            //std::cout << i << std::endl;
            i++;
            //for (int i = 0; i < 4000; i++){}
            myWindow->clear();
            tiden = tiden - myClock.getElapsedTime().asSeconds();
            //std:: cout << "Tid kvar: " << tiden << std::endl;
            //std::cout << "LIV: " << Controller::controller.get_lives() << std::endl;
            if(!myGame.shall_feed)
            {
                // std::cout << "Tryck på N för att starta nästa wave" << std::endl;
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
