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
    if (feeding_time - time_passed <= 0)
    {
        if(current_sheep < current_wave.size()) //är vi inne?
        {
            int sheep_number = current_wave.at(current_sheep);
            if (current_wave.at(sheep_number) == 1)
            {
                EasySheep* tempEasySheep = new EasySheep(GameBoard->get_Course());
                GameBoard->set_Sheep(tempEasySheep);
                feeding_time = 100;
            }
            else if (current_wave.at(sheep_number) == 2)
            {
                MediumSheep* tempMediumSheep = new MediumSheep(GameBoard->get_Course());
                GameBoard->set_Sheep(tempMediumSheep);
                feeding_time = 100;
            }
            else if (current_wave.at(sheep_number) == 3)
            {
                HardSheep* tempHardSheep = new HardSheep(GameBoard->get_Course());
                GameBoard->set_Sheep(tempHardSheep);
                feeding_time = 100;
            }
            else
            {
                //Ska inte hända
            }
            current_sheep = current_sheep + 1;
            if (current_wave.size() == current_sheep) //slutet på waven, har kan man kalla på pause
            {
                shall_feed = false;
                std::cout << "Kommer jag hit" << std::endl;
                current_level = current_level + 1; //nästa wave då
                std::cout << "Så här lång är wave: " << wave.size() << std::endl;
                if (current_level >= wave.size())
                {
                    std::cout << "slut på vågor" << std::endl;
                    //då är det slut
                }
                else
                {
                    std::cout << "ny level!" << std::endl;
                    current_sheep = 0;
                    current_wave = wave.at(current_level);
                    change_run();
                }
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



void Game::update_Game(float time)
{
    if (GameBoard->get_Sheep().size() != 0)
    {
        for (unsigned int i = 0; i < GameBoard->get_Sheep().size(); i++)
        {
            if (GameBoard->get_Sheep().at(i)->am_i_hit)
            {
                delete GameBoard->get_Sheep().at(i);
                GameBoard->get_Sheep().erase(GameBoard->get_Sheep().begin()+i);
            }
            else if (GameBoard->get_Sheep().at(i)->update_position(time))
            {
                delete GameBoard->get_Sheep().at(i);
                GameBoard->get_Sheep().erase(GameBoard->get_Sheep().begin()+i);
            }

        }
    }
    for (unsigned int i = 0; i < GameBoard->get_Shot().size(); i++)
    {
        if (GameBoard->get_Shot().at(i)->did_i_hit)
        {
            delete GameBoard->get_Shot().at(i);
            GameBoard->get_Shot().erase(GameBoard->get_Shot().begin()+i);
        }
        else
        {
            GameBoard->get_Shot().at(i)->hunt_sheep(time);
        }
    }


    if(GameBoard->get_Tower().size() != 0)
    {
        for (unsigned int i = 0; i < GameBoard->get_Tower().size(); i++)
        {
            GameBoard->get_Tower().at(i)->locate_sheep(GameBoard->get_Sheep(),time);
        }
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
    GameWindow->draw(GameBoard->get_Board_Sprite());

    for (int i = 0; i < 6; i++)
    {
        GameBoard->get_Course().get_Course_Sprite(i).setTexture(TextureHandler::texturehandler.getCourse());
        GameWindow->draw(GameBoard->get_Course().get_Course_Sprite(i));

    }
}

void Game::update_foreground_graphics()
{

    for (unsigned int i = 0; i < GameBoard->get_Shot().size(); i ++)
    {
        if (GameBoard->get_Shot().size() != 0)
        {
            GameWindow->draw(GameBoard->get_Shot().at(i)->get_Shot_Sprite());
        }
    }

    if (GameBoard->get_Sheep().size() >= 0)
    {
        for (unsigned int i = 0; i < GameBoard->get_Sheep().size(); i++)
        {
            GameWindow->draw(GameBoard->get_Sheep().at(i)->get_Sheep_Sprite());
        }
    }

    if (GameBoard->get_Tower().size() >= 0)
    {
        for (unsigned int i = 0; i < GameBoard->get_Tower().size(); i++)
        {


            GameWindow->draw(GameBoard->get_Tower().at(i)->get_Tower_Sprite());//Finns get_Tower_Sprite?
        }
    }


}

bool Game::is_running()
{
    return start_stop;
}

void Game::change_run()
{
    if(is_running())
    {
        start_stop = false;
    }
    else
    {
        start_stop = true;
    }
}

bool Game::is_shopping()
{
    return can_I_shop;
}

void Game::change_shop()
{
    if(is_shopping())
    {
        can_I_shop = false;
    }
    else
    {
        can_I_shop = true;
    }
}

void Game::new_wave()
{
    if (current_level >= wave.size()) // är vågorna slut?
    {
        std::cout << "slut på får" << std::endl;
        //då är det slut
    }
    else
    {
        std::cout << "ny level!" << std::endl;
        current_sheep = 0;
        current_wave =  wave.at(current_level);
        change_run();
    }
    shall_feed = true;

}
