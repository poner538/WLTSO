/*
* FILNAMN:          Game.cc
* PROGRAMMERARE:    Johanna Laidla  910712-5826, Y3a
*                   Ema Becirovic   920510-6249, Y3a
* DATUM:            2013-12-19
*
* BESKRIVNING
*
* Klassen Game används för att uppdatera och skapa objekt och styra spelet.
* det finns också medlemmar som innehåller sekvenser av hur fåren ska komma ut.
*/

#include <SFML/Audio.hpp>
#include "Game.h"
#include "Board.h"
#include "Sheep.h"
#include <iostream>
#include <ostream>
#include <sstream>

//Konstruktor
Game::Game(sf::RenderWindow*& new_Window, Board*& new_Board)
{
    GameWindow = new_Window;
    GameBoard = new_Board;
    current_wave = wave.at(current_level);
}

//Matar ut får när det ar aktuellt
void Game::feed_Sheep(float time_passed)
{
    //Fåren får inte komma för ofta
    if (feeding_time - time_passed <= 0)
    {
        if(current_sheep < current_wave.size()) //är vi inne?
        {
            int sheep_number = current_wave.at(current_sheep);
            if (sheep_number == 1)
            {
                EasySheep* tempEasySheep = new EasySheep(GameBoard->get_Course());
                GameBoard->set_Sheep(tempEasySheep);
                feeding_time = 20;
            }
            else if (sheep_number == 2)
            {
                MediumSheep* tempMediumSheep = new MediumSheep(GameBoard->get_Course());
                GameBoard->set_Sheep(tempMediumSheep);
                feeding_time = 20;
            }
            else if (sheep_number == 3)
            {
                HardSheep* tempHardSheep = new HardSheep(GameBoard->get_Course());
                GameBoard->set_Sheep(tempHardSheep);
                feeding_time = 20;
            }
            else
            {
                BossSheep* tempBossSheep = new BossSheep(GameBoard->get_Course());
                GameBoard->set_Sheep(tempBossSheep);
                feeding_time = 20;
            }

            current_sheep = current_sheep + 1;
            if (current_wave.size() == current_sheep) //Waven är slut
            {
                shall_feed = false;
                current_level = current_level + 1; //Nästa wave
                if (current_level < wave.size())
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

//En uppdateringsloop
void Game::update_Game(float time)
{
    //Kan jag handla den här uppdateringen?
    if((!shall_feed) and (GameBoard->get_Sheep().size()==0))
    {
        can_I_shop = true;
    }
    //Är spelet slut
    if ((GameBoard->get_Sheep().size()==0) and (current_level >= wave.size()))
    {
        ending = true;
    }
    //Uppdaterar fårens position och skjuter på dessa
    if (GameBoard->get_Sheep().size() > 0)
    {
        for (unsigned int i = 0; i < GameBoard->get_Sheep().size(); i++)
        {
            if (GameBoard->get_Sheep().at(i)->get_death() or GameBoard->get_Sheep().at(i)->update_position(time))
            {
                for (unsigned int i = 0; i < GameBoard->get_Shot().size(); i++)
                {
                    //Om skottets får har dött så ska skottet raderas
                    if (GameBoard->get_Shot().at(i)->is_target())
                    {
                        delete GameBoard->get_Shot().at(i);
                        GameBoard->get_Shot().erase(GameBoard->get_Shot().begin()+i);
                        i = i - 1;
                    }
                }
                //Efter att skottet har raderats ska fåret raderas
                delete GameBoard->get_Sheep().at(i);
                GameBoard->get_Sheep().erase(GameBoard->get_Sheep().begin()+i);
                set_sound1(true);
            }
        }
    }

    //Uppdaterar skottens position
    for (unsigned int i = 0; i < GameBoard->get_Shot().size(); i++)
    {
        //Men tar bort dem om de har träffat ett får
        if (GameBoard->get_Shot().at(i)->get_did_I_hit())
        {
            delete GameBoard->get_Shot().at(i);
            GameBoard->get_Shot().erase(GameBoard->get_Shot().begin()+i);
        }
        else
        {
            GameBoard->get_Shot().at(i)->hunt_sheep(time);
        }
    }

    //Tornen letar upp får att skjuta på
    if(GameBoard->get_Tower().size() != 0 and GameBoard->get_Sheep().size() != 0)
    {
        for (unsigned int i = 0; i < GameBoard->get_Tower().size(); i++)
        {
            GameBoard->get_Tower().at(i)->locate_sheep(GameBoard->get_Sheep(),time);
        }
        if (Controller::controller.get_made_shot())
        {
            sound2 = true;
            Controller::controller.change_made_shot(false);
        }
    }

}

//Funktion som körs när spelet är slut
void Game::game_over(std::string name)
{
    //En text med spelarens namn och poäng kommer upp på skärmen
    std::ostringstream pointinput;
    pointinput << Controller::controller.get_points();
    std::string pointstring = pointinput.str();
    std::string gameoverstring = "GAME OVER! \nScore: ";
    std::string namestring = "Name: ";

    gameoverstring = gameoverstring + pointstring + "\n" + namestring + name;
    sf::Font arial;
    arial.loadFromFile("arial.ttf");
    sf::Text gameovertext{gameoverstring, arial};
    gameovertext.setPosition(310,20);
    gameovertext.setColor(sf::Color::Black);
    GameWindow->draw(gameovertext);

    //Alla skott och torn raderas
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

//Bakgrundsgrafiken uppdateras
void Game::update_background_graphics()
{
    GameWindow->draw(GameBoard->get_Board_Sprite());

    for (int i = 0; i < 6; i++)
    {
        GameWindow->draw(GameBoard->get_Course().get_Course_Sprite(i));
    }
}

//Fårens, tornens och skottens grafik uppdateras
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

//Returnerar sanningsvärde om spelet är igång
bool Game::is_running()
{
    return start_stop;
}

void Game::change_run(bool t)
{
    start_stop = t;
}

//Ändrar möjligheten att shoppa
void Game::change_shopping(bool ny)
{
    can_I_shop = ny;

}

//Returnerar sanningsvärde om man får shoppa
bool Game::is_shopping()
{
    return can_I_shop;
}

//Sätter igång en ny våg av får
void Game::new_wave()
{
    if (current_level < wave.size()) // år vågorna slut?
    {
        current_sheep = 0;
        current_wave =  wave.at(current_level);
        shall_feed = true;
    }
}

//Funktioner för ljudeffekter
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

//Returnerar vilken nivå spelaren är på
int Game::get_level()
{
    return current_level + 1;
}

//Returnerar/ändrar om får skall matas
bool Game::is_feeed()
{
    return shall_feed;
}

void Game::change_feed(bool t)
{
    shall_feed = t;
}

//Returnerar/ändrar om spelet är slut
bool Game::is_ending()
{
    return ending;
}

void Game::change_ending(bool t)
{
    ending = t;
}
