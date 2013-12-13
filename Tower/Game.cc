/*
* FILNAMN:          Game.cc
* PROGRAMMERARE:    Johanna Laidla  910712-5826, Y3a
                    Ema Becirovic   920510-6249, Y3a
* DATUM:            2013-mm-dd
*
* BESKRIVNING
*
*
*/
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow* new_Window, Board* new_Board)
{
    GameWindow = new_Window;
    GameBoard = new_Board;
}

void feed_sheep(float time_passed, int current_wave, int sheep_number)
{
    if(feeding_time - time_passed <= 0)
    {
        if(sheep_number <= wave.current_wave.size() - 1) //den här kollen borde man kunna ha i en annan funktion
        {
            if (current_wave.at(sheep_number) == 1)
            {
                new EasySheep(GameBoard->get_Course());
                feeding_time = 10;
            }
            else if (current_wave.at(sheep_number) == 2)
            {
                new MediumSheep(GameBoard->get_Course());
                feeding_time = 10;
            }
            else if (current_wave.at(sheep_number) == 3)
            {
                new MediumSheep(GameBoard->get_Course());
                feeding_time = 10;
            }
            else
            {
                //Ska inte hända
            }
            current_sheep = current_sheep + 1;
        }
        return;
    }
    else
    {
        feeding_time = feeding_time - time_passed;
        return;
    }
}

/*void Game::feed_Sheep(vector<int> current_wave)
{

}*/

void Game::update_Game(float time)
{
    for (int i = 0; i < GameBoard->get_Sheep().size() - 1; i++)
    {
        GameBoard->get_Sheep().at(i)->update_position(time));
    }
    for (int i = 0; i < GameBoard->get_Shot().size() - 1; i++)
    {
        GameBoard->get_Shot().at(i)->hunt_sheep(time);
    }
}

void Game::game_on()
{

}

void Game::game_over()
{
    std::cout << "game over" << std::endl;
}

void Game::update_background_graphics()
{
    for (int i = 0; i < 6; i++)
    {
        GameWindow->draw(GameBoard->get_Course().get_Course_Sprite(i));
    }
}

void Game::update_foreground_graphics()
{
    for (int i = 0; i < GameBoard->get_Sheep().size() - 1; i++)
    {
        GameWindow->draw(GameBoard->get_Sheep().at(i)->get_Sheep_Sprite());
    }
    for (int i = 0; i < GameBoard->get_Tower().size() - 1; i++)
    {
        GameWindow->draw(GameBoard->get_Tower().at(i)->get_Tower_Sprite());//Finns get_Tower_Sprite?
    }
    for (int i = 0; i < GameBoard->get_Shot().size() - 1; i ++)
    {
        GameWindow->draw(GameBoard->get_Shot().at(i)->get_Shot_Sprite());
    }

}
