/*
* FILNAMN:          Shot.h
* PROGRAMMERARE:    Johanna Laidla      910712-5826, Y3a
                    Ema Becirovic       920510-6249, Y3a
                    Karin Lockowandt    910213-3260, Yi3
                    Daniel Brattgård    900926-3394, Y3a
                    Pontus Erlesand     910117-1172, Y3a
                    Marie Ekbrant       890401-2740, Y3a
* DATUM:            2013-12-19
*
* Headerfil till klassen Shot.
*
*
*/

#ifndef SHOT_H
#define SHOT_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Sheep.h"
#include "Course.h"

/*

Klassen Shot ska tilldelas ett får, en skada den ska göra och en startposition

*/


class Shot
{
public:
    /*The big 5*/
    Shot(Sheep*&, int, pos);
    ~Shot();
    Shot(const Shot& other) = delete; //Kopieringskonstruktor
    Shot(const Shot&& other) = delete; //Kopieringskonstruktor med move
    Shot& operator=(const Shot& other) = delete; //Tilldelningsoperator
    Shot& operator=(const Shot&& other) = delete; //Tilldelningspoperator med move

    /*Medlemsfunktioner*/
    bool is_target();
    int get_dmg();
    void hunt_sheep(float);
    sf::Sprite get_Shot_Sprite();
    bool get_did_i_hit();

private:
    /*Datamedlemmar*/
    int dmg;
    pos shot_pos;
    Sheep* target;
    sf::Sprite Shot_Sprite;
    int speed = 450;
    bool did_i_hit = false;

    /*Privat medlemmsfunktion*/
    void hit_sheep();

};


#endif
