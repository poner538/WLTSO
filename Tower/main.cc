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

int main()
{
    sf::RenderWindow* myWindow = new sf::RenderWindow(sf::VideoMode(800,600), "Who let the sheep out?");
    Course myCourse;
    Board* myBoard = new Board(myCourse);
    Game myGame(myWindow, myBoard);
    sf::Clock myClock;
    float tiden = 10;
    int i = 0;
    sf::Event event;
    int tower_width = 50;
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

        myGame.update_Game(myClock.getElapsedTime().asSeconds()*50);
        myClock.restart();
        myGame.update_background_graphics();
        myGame.update_foreground_graphics();
        myWindow->display();
        //std::cout << i << std::endl;
        i++;
        //for (int i = 0; i < 4000; i++){}
        myWindow->clear();
        tiden = tiden - myClock.getElapsedTime().asSeconds();
        std:: cout << "Tid kvar: " << tiden << std::endl;
    }
    return 0;
}
