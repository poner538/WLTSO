/*
* FILNAMN:          Game.cc
* PROGRAMMERARE:    Johanna Laidla  910712-5826, Y3a
*                   Ema Becirovic   920510-6249, Y3a
* DATUM:            2013-mm-dd
*
* BESKRIVNING
*
*
*/
#include "Game.h"

Game::Game(sf::Window new_Window, Board new_Board)
{
    GameWindow = new_Window;
    GameBoard = new_Board;
}

void Game::feed_Sheep(vector<int> current_wave)
{

}

void Game::game_on()
{

}

void Game::game_over()
{

}

void Game::update_background_graphics()
{
    for (i = 0; i < 6; i++)
    {
        GameWindow.draw(GameBoard.get_Course.get_Course_Sprite(i));
    }
}

void Game::update_foreground_graphics()
{
    for (i = 0; i < GameBoard.get_Sheep.size() - 1; i++)
    {
        GameWindow.draw(GameBoard.get_Sheep.at(i)->get_Sheep_Sprite());
        GameWindow.draw(GameBoard.get_Tower.at(i)->get_Tower_Sprite());//Finns get_Tower_Sprite?
    }

}
