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
    void build_tower1();
    void build_tower2();








private:








};
#endif
