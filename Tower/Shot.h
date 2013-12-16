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

Klassen Shot ska tilldelas ett f�r, en skada den ska g�ra och en startposition

*/


class Shot
{
public:
    Shot(Sheep*, int, pos);
    ~Shot();

    int get_dmg();
<<<<<<< HEAD
    void hunt_sheep(float);
=======
    void hunt_sheep();
    sf::Sprite get_Shot_Sprite();
>>>>>>> ee102580a027411ded11e2a2426c7660d091d4ad


private:
    int dmg;
    pos shot_pos;
    Sheep* target;
    sf::Sprite Shot_Sprite;
    void hit_sheep();
    int speed;

};


#endif
