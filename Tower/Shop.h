/*
 * FILNAMN:       Shop.h
 * PROGRAMMERARE: Daniel Brattgård 900926-3394, Y3a
 *                Marie Ekbrant 890401-2740, Y3a
 * DATUM:         2013-12-
 *
 * BESKRIVNING
 * Handla saker
 */

#ifndef SHOP_H
#define SHOP_H
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

class Board;
class Controller;


class Shop
{
public:
    Shop(Board*, sf::RenderWindow*&);
    ~Shop();


    void update_scoreboard();


    //sf::Sprite get_Shop_Sprite();

    bool is_Catapult_button(int,int);
    bool is_Shooting_button(int,int);
    bool is_start_button(int,int);
    bool is_stop_button(int,int);
    bool is_wave_button(int,int);


private:

    //Knappar till tornbyggen
    int tower_button_width = 80;
    int tower_button_height = 180;
    sf::Rect<int> Catapult_tower_button{sf::Rect<int>(610,210, tower_button_width, tower_button_height)};
    sf::Rect<int> Shooting_tower_button{sf::Rect<int>(710,210, tower_button_width, tower_button_height)};

    //Knappar till start, stop och ny våg
    int wave_width = 180;
    int wave_height = 80;
    int startstop_width = 80;
    int startstop_height = 80;
    sf::Rect<int> New_Wave_button{sf::Rect<int>(610,410, wave_width, wave_height)};
    sf::Rect<int> Start_button{sf::Rect<int>(610,510, startstop_width, startstop_height)};
    sf::Rect<int> Stop_button{sf::Rect<int>(710,510, startstop_width, startstop_height)};

    sf::RenderWindow* GameWindow;
    Board* GameBoard;
    sf::Event* GameEvent;
};
#endif
