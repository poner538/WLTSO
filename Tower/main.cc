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

int main()
{

    sf::RenderWindow* myWindow = new sf::RenderWindow(sf::VideoMode(800,600), "Who let the sheep out?");
    Course myCourse;
    Board* myBoard = new Board(myCourse);
    Game myGame(myWindow, myBoard);
    sf::Time timer;
    while(myGame.game_over != true)
    {
        while(myGame.start_stop == true)
        {
            sf::Clock clocker;
            std::cerr << timer.asSeconds() << std::endl;
            myGame.update_Game(timer.asSeconds());
            myGame.update_background_graphics();
            myGame.update_foreground_graphics();
            myWindow->display();
            timer = clocker.getElapsedTime();
        }
    }
    return 0;
}
