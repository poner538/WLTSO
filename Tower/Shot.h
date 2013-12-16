/*
* FILNAMN:          Shot.h
* PROGRAMMERARE:    Pontus Erlesand   910117-1172, Y3a
                    Karin Lockowandt  910213-3262, Yi3
* DATUM:            2013-mm-dd
*
* BESKRIVNING
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
    Shot(Sheep*, int, pos);
    ~Shot();

    int get_dmg();
    void hunt_sheep(float);


private:
    int dmg;
    pos shot_pos;
    Sheep* target;
    //sf::Image ShotImage(".jpg");
    //sf::Sprite ShotSprite(ShotImage);
    void hit_sheep();
    int speed;

};


#endif
