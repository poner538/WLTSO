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
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        sf::Vector2i position = sf::Mouse::getPosition(*myWindow);
                        int xpressed = event.mouseButton.x;
                        int ypressed = event.mouseButton.y;
                        int xplus = xpressed + tower_width;
                        int yplus = ypressed + tower_width;
                        //Börja kolla möjliga fall
                        if(!myBoard->exist(pos {xpressed,ypressed}) and (!myBoard->exist(pos {xplus,ypressed})) and (!myBoard->exist(pos {xpressed,yplus})) and (!myBoard->exist(pos {xplus,yplus})))
                        {
                            pos Towerpos {xpressed, ypressed};
                            Tower* myTower = new Catapult_tower(Towerpos, myBoard);
                            myBoard->set_Tower(myTower);
                        }
                    }
                }
            }
            /*if (!myGame.shall_feed)//denna ifsatsen funkar inte av någon anledning
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

            /*while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i position = sf::Mouse::getPosition(*myWindow);
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
                        std::cout << "Nej det får du inte!" << std::endl;
                    }
                }
            }

            while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
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
                        std::cout << "Nej det får du inte!" << std::endl;
                    }
                }
            }*/

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
