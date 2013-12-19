/*
* FILNAMN:          Shop.h
* PROGRAMMERARE:    Johanna Laidla      910712-5826, Y3a
                    Ema Becirovic       920510-6249, Y3a
                    Karin Lockowandt    910213-3260, Yi3
                    Daniel Brattgård    900926-3394, Y3a
                    Pontus Erlesand     910117-1172, Y3a
                    Marie Ekbrant       890401-2740, Y3a
* DATUM:            2013-12-19
*
* Headerfil till klassen Shop.
*
*
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
    Shop(const Shop& other) = delete; //Kopieringskonstruktor
    Shop(const Shop&& other) = delete; //Kopieringskonstruktor med move
    Shop& operator=(const Shop& other) = delete; //Tilldelningsoperator
    Shop& operator=(const Shop&& other) = delete; //Tilldelningspoperator med move

    void update_scoreboard();
    bool is_Catapult_button(int,int);
    bool is_Shooting_button(int,int);
    bool is_start_button(int,int);
    bool is_stop_button(int,int);
    bool is_wave_button(int,int);
    bool is_volume_minus_button(int,int);
    bool is_volume_plus_button(int,int);


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

    //Knappar till volymkontroll
    int volume_width = 80;
    int volume_height = 80;
    sf::Rect<int> Volume_minus_button{sf::Rect<int>(610,110,volume_width, volume_height)};
    sf::Rect<int> Volume_plus_button{sf::Rect<int>(710,110,volume_width, volume_height)};

    sf::RenderWindow* GameWindow;
    Board* GameBoard;
};
#endif
