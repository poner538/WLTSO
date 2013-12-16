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
#include "Board.h"
#include "Sheep.h"
#include <iostream>

Game::Game(sf::RenderWindow*& new_Window, Board*& new_Board)
{
    GameWindow = new_Window;
    GameBoard = new_Board;
    current_wave = wave.at(current_level);
}

void Game::feed_Sheep(float time_passed)
{
    int sheep_number = current_wave.at(current_sheep);
    if (feeding_time - time_passed <= 0)
    {
        if(current_sheep < current_wave.size() - 1) //är vi inne?
        {
            if (current_wave.at(sheep_number) == 1)
            {
                EasySheep* tempEasySheep = new EasySheep(GameBoard->get_Course());
                GameBoard->set_Sheep(tempEasySheep);
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
            if (current_wave.size() == current_sheep - 1) //slutet på waven, har kan man kalla på pause
            {
                current_level = current_level + 1; //nästa wave då
                if (current_level == wave.size()) // är vågorna slut?
                {
                    //då är det slut
                }
            }
            else
            {
                current_wave = wave.at(current_sheep);
            }
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
    for (unsigned int i = 0; i < GameBoard->get_Sheep().size() - 1; i++)
    {
        GameBoard->get_Sheep().at(i)->update_position(time);
    }
    for (unsigned int i = 0; i < GameBoard->get_Shot().size() - 1; i++)
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
    GameBoard->get_Board_Sprite().setTexture(TextureHandler::texturehandler.getBoard());
    GameWindow->draw(GameBoard->get_Board_Sprite());

    for (int i = 0; i < 6; i++)
    {
        GameBoard->get_Course().get_Course_Sprite(i).setTexture(TextureHandler::texturehandler.getCourse());
        GameWindow->draw(GameBoard->get_Course().get_Course_Sprite(i));

    }
    GameWindow->display();
}

void Game::update_foreground_graphics()
{
    for (unsigned int i = 0; i <= GameBoard->get_Sheep().size(); i++)
    {
        if (GameBoard->get_Sheep().size() != 0)
        {
            GameBoard->get_Sheep().at(i)->get_Sheep_Sprite().setTexture(TextureHandler::texturehandler.getEasySheep());
            GameWindow->draw(GameBoard->get_Sheep().at(i)->get_Sheep_Sprite());
        }
    }
    for (unsigned int i = 0; i <= GameBoard->get_Tower().size(); i++)
    {
        if (GameBoard->get_Tower().size() != 0)
        {

            GameWindow->draw(GameBoard->get_Tower().at(i)->get_Tower_Sprite());//Finns get_Tower_Sprite?
        }
    }
    for (unsigned int i = 0; i <= GameBoard->get_Shot().size(); i ++)
    {
        if (GameBoard->get_Shot().size() != 0)
        {
            GameWindow->draw(GameBoard->get_Shot().at(i)->get_Shot_Sprite());
        }
    }

}
