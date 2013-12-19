/*
 * FILNAMN:       Shop.cc
 * PROGRAMMERARE: Daniel Brattgård 900926-3394, Y3a
 *                Marie Ekbrant 890401-2740, Y3a
 * DATUM:         2013-12-
 *
 * BESKRIVNING
 * Handla saker
 */

#include "Shop.h"
#include "Board.h"
#include "Controller.h"
#include "Sheep.h"
#include "Tower.h"
#include <sstream>


Shop::Shop(Board* new_board, sf::RenderWindow*& new_window)
{
    GameBoard = new_board;
    GameWindow = new_window;
}

Shop::~Shop()
{
    GameWindow = nullptr;
    delete GameWindow;
    GameBoard = nullptr;
    delete GameBoard;
}

void Shop::update_scoreboard()//Borde snyggas till
{
    std::ostringstream result;
    result << Controller::controller.get_lives();
    std::string tvan = result.str();
    std::string ettan = "Lives: ";
    ettan = ettan + tvan;
    sf::Font arial;
    arial.loadFromFile("arial.ttf");
    sf::Text liv {ettan, arial};
    liv.setPosition(610,10);
    liv.setColor(sf::Color::Black);
    GameWindow->draw(liv);

    std::ostringstream result2;
    result2 << Controller::controller.get_gold();
    std::string tvan2 = result2.str();
    ettan = "Gold: ";
    ettan = ettan+ tvan2;
    sf::Text guld {ettan, arial};
    guld.setPosition(610,40);
    guld.setColor(sf::Color::Black);
    GameWindow->draw(guld);

    std::ostringstream result3;
    result3 << Controller::controller.get_points();
    std::string tvan3 = result3.str();
    ettan = "Score: ";
    ettan = ettan + tvan3;
    sf::Text p {ettan, arial};
    p.setPosition(610,70);
    p.setColor(sf::Color::Black);
    GameWindow->draw(p);
}


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
