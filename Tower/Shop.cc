/*
 * FILNAMN:       Shop.cc
 * PROGRAMMERARE: Daniel Brattgård 900926-3394, Y3a
 *                Marie Ekbrant 890401-2740, Y3a
 * DATUM:         2013-12-19
 *
 * BESKRIVNING
 *
 * Handla och uppdatera scoreboard.
 *
 */

#include "Shop.h"
#include "Board.h"
#include "Controller.h"
#include "Sheep.h"
#include "Tower.h"
#include <sstream>

//Konstruktor
Shop::Shop(Board* new_board, sf::RenderWindow*& new_window)
{
    GameBoard = new_board;
    GameWindow = new_window;
}

//Destruktor
Shop::~Shop()
{
    GameWindow = nullptr;
    delete GameWindow;
    GameBoard = nullptr;
    delete GameBoard;
}

/*Skriver ut hur mycket liv, guld respektive poäng man har*/
void Shop::update_scoreboard()
{

    std::ostringstream lives_left;
    lives_left << Controller::controller.get_lives();
    std::string num_of_lives_left = lives_left.str();
    std::string text_shop = "Lives: ";
    text_shop = text_shop + num_of_lives_left;
    sf::Font arial;
    arial.loadFromFile("arial.ttf");
    sf::Text lives {text_shop, arial};
    lives.setPosition(610,10);
    lives.setColor(sf::Color::Black);
    GameWindow->draw(lives);

    std::ostringstream gold_out;
    gold_out << Controller::controller.get_gold();
    std::string ammount_of_gold = gold_out.str();
    text_shop = "Gold: ";
    text_shop = text_shop + ammount_of_gold;
    sf::Text gold {text_shop, arial};
    gold.setPosition(610,40);
    gold.setColor(sf::Color::Black);
    GameWindow->draw(gold);

    std::ostringstream score_out;
    score_out << Controller::controller.get_points();
    std::string score = score_out.str();
    text_shop = "Score: ";
    text_shop = text_shop + score;
    sf::Text score_txt {text_shop, arial};
    score_txt.setPosition(610,70);
    score_txt.setColor(sf::Color::Black);
    GameWindow->draw(score_txt);
}

//följande funktioner returnerar rätt knappar.
bool Shop::is_Catapult_button(int x, int y)
{
    return Catapult_tower_button.contains(x,y);
}

bool Shop::is_Shooting_button(int x, int y)
{
    return Shooting_tower_button.contains(x,y);
}

bool Shop::is_start_button(int x,int y)
{
    return Start_button.contains(x,y);
}

bool Shop::is_stop_button(int x, int y)
{
    return Stop_button.contains(x,y);
}

bool Shop::is_wave_button(int x, int y)
{
    return New_Wave_button.contains(x,y);
}

bool Shop::is_volume_minus_button(int x, int y)
{
    return Volume_minus_button.contains(x,y);
}

bool Shop::is_volume_plus_button(int x, int y)
{
    return Volume_plus_button.contains(x,y);
}
