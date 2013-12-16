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
#include <Event.hpp>
#include "Board.h"
#include "Tower.h"


//Andra includes

class Shop
{
public:
    Shop();
    ~Shop();
    sf::Image ShopImage(bildnamn.jpg);
    sf::Sprite ShopSprite(ShopImage.jpg);
    int price_tower1;
    int price_tower2;
    int width;



    //Medlemsfunktioner
    void build_Catapult_Tower();
    void build_Shooting_Tower();

    //Knappar till tornbyggen
    int button_width = 80; //ex bredd
    int button_height = 200 //ex höjd
    sf::Rect<int> Tower_knapp1{sf::Rect<int>(610,300, button_width, button_height)};
    sf::Rect<int> Tower_knapp2{sf::Rect<int>(710,300, button_width, button_height)};








private:








};
#endif
