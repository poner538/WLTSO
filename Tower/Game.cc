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
#include <SFML/Audio.hpp>
#include "Game.h"
#include "Board.h"
#include "Sheep.h"
#include <iostream>
#include <ostream>
#include <sstream>

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
            if (sheep_number == 1)
            {
                EasySheep* tempEasySheep = new EasySheep(GameBoard->get_Course());
                GameBoard->set_Sheep(tempEasySheep);
                feeding_time = 6;
            }
            else if (sheep_number == 2)
            {
                MediumSheep* tempMediumSheep = new MediumSheep(GameBoard->get_Course());
                GameBoard->set_Sheep(tempMediumSheep);
                feeding_time = 6;
            }
            else if (sheep_number == 3)
            {
                HardSheep* tempHardSheep = new HardSheep(GameBoard->get_Course());
                GameBoard->set_Sheep(tempHardSheep);
                feeding_time = 6;
            }
            else if (sheep_number == 1337)
            {
                BossSheep* tempBossSheep = new BossSheep(GameBoard->get_Course());
                GameBoard->set_Sheep(tempBossSheep);
                feeding_time = 6;
            }
            else
            {
                //Ska inte hända
            }
            current_sheep = current_sheep + 1;
            if (current_wave.size() == current_sheep) //slutet på waven, har kan man kalla på pause
            {
                shall_feed = false;
                current_level = current_level + 1; //nästa wave då
                if (current_level >= wave.size())
                {
                    //slut på får
                }
                else
                {
                    current_sheep = 0;
                    current_wave = wave.at(current_level);
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
    if((!shall_feed) and (GameBoard->get_Sheep().size()==0))
    {
        can_I_shop = true;
    }
    if ((GameBoard->get_Sheep().size()==0) and (current_level >= wave.size()))
    {
        ending = true;
    }
    if (GameBoard->get_Sheep().size() > 0)
    {
        for (unsigned int i = 0; i < GameBoard->get_Sheep().size(); i++)
        {
            if (GameBoard->get_Sheep().at(i)->am_i_dead or GameBoard->get_Sheep().at(i)->update_position(time))
            {
                for (unsigned int i = 0; i < GameBoard->get_Shot().size(); i++)
                {
                    if (GameBoard->get_Shot().at(i)->is_target())
                    {
                        delete GameBoard->get_Shot().at(i);
                        GameBoard->get_Shot().erase(GameBoard->get_Shot().begin()+i);
                        i = i - 1;
                    }
                }
                delete GameBoard->get_Sheep().at(i);
                GameBoard->get_Sheep().erase(GameBoard->get_Sheep().begin()+i);
                set_sound1(true);
            }
        }
    }
    else if (current_wave.size() <= current_sheep)
    {
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

    if(GameBoard->get_Tower().size() != 0 and GameBoard->get_Sheep().size() != 0)
    {
        for (unsigned int i = 0; i < GameBoard->get_Tower().size(); i++)
        {
            GameBoard->get_Tower().at(i)->locate_sheep(GameBoard->get_Sheep(),time);
        }
        if (Controller::controller.made_shot)
        {
            sound2 = true;
            Controller::controller.made_shot = false;
        }
    }

}

void Game::game_on()
{

}

void Game::game_over(std::string name)
{

    //update_Game(float 0);
    std::ostringstream result4;
    result4 << Controller::controller.get_points();
    std::string tvan4 = result4.str();
    std::string ettan = "GAME OVER! \nPoäng: ";
    std::string trean = "Namn: ";

    ettan = ettan + tvan4 + "\n" + trean + name;
    sf::Font arial;
    arial.loadFromFile("arial.ttf");
    sf::Text p {ettan, arial};
    p.setPosition(310,20);
    p.setColor(sf::Color::Black);
    GameWindow->draw(p);

    for (unsigned int i = 0; i < GameBoard->get_Shot().size(); i++)
    {
        delete GameBoard->get_Shot().at(i);
        GameBoard->get_Shot().erase(GameBoard->get_Shot().begin()+i);
        i = i - 1;
    }

    for (unsigned int i = 0; i < GameBoard->get_Tower().size(); i++)
    {
        delete GameBoard->get_Tower().at(i);
        GameBoard->get_Tower().erase(GameBoard->get_Tower().begin()+i);
        i = i - 1;
    }
}

void Game::update_background_graphics()
{
    GameWindow->draw(GameBoard->get_Board_Sprite());

    for (int i = 0; i < 6; i++)
    {
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
            GameWindow->draw(GameBoard->get_Tower().at(i)->get_Tower_Sprite());
        }
    }


}

bool Game::is_running()
{
    return start_stop;
}

void Game::change_run(bool t)
{
    start_stop = t;
}

void Game::change_shopping(bool ny)
{
    can_I_shop = ny;

}

bool Game::is_shopping()
{
    return can_I_shop;
}


void Game::new_wave()
{
    if (current_level >= wave.size()) // är vågorna slut?
    {
        //då är det slut
    }
    else
    {
        current_sheep = 0;
        current_wave =  wave.at(current_level);
        shall_feed = true;
    }


}


bool Game::is_sound1()
{
    return sound1;
}

void Game::set_sound1(bool t)
{
    sound1 = t;
}

bool Game::is_sound2()
{
    return sound2;
}

void Game::set_sound2(bool t)
{
    sound2 = t;
}

int Game::get_level()
{
    return current_level + 1;
}
