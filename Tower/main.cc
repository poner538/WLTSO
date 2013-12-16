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

    myGame.update_background_graphics();




    myGame.update_foreground_graphics();



    //myWindow->display();

    for (unsigned int i = 0; i < 400000000000000; i++)
    {

    }

    return 0;
}
