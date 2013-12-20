/*
* FILNAMN:          Controller.cc
* PROGRAMMERARE:    Johanna Laidla  910712-5826, Y3a
                    Ema Becirovic   920510-6249, Y3a
* DATUM:            2013-12-19
*
* BESKRIVNING
*
* Controller ska hålla räkningen på poäng, guld och antal liv.
*
*/

#include "Controller.h"
#include <iostream>

Controller Controller::controller(100,3);

Controller::Controller(int new_gold, int new_lives)
{
    gold = new_gold;
    current_lives = new_lives;
    points = 0;
}


bool Controller::gold_check(const int value)
{
    if((gold + value) < 0)
        return false;
    else
        return true;
}

/* Uppdaterar guldinnehav (vid köp av torn samt när man dödar får)*/
void Controller::change_gold(const int value)
{
    gold = gold + value;
}

/* Uppdaterar poänginnehav (när man dödar får)*/
void Controller::change_points(const int value)
{
    points = points + value;
}

/* Drar bort ett liv när ett får lyckats ta sig genom hela banan*/
void Controller::lives()
{
    current_lives = current_lives - 1;
}

/* Returnerar aktuellt antal liv */
int Controller::get_lives()
{
    return current_lives;
}

/* Returnerar aktuell mängd guld*/
int Controller::get_gold()
{
    return gold;
}

/* Returnerar aktuellt antal poäng */
int Controller::get_points()
{
    return points;
}

bool Controller::get_made_shot()
{
    return made_shot;
}

void Controller::change_made_shot(bool t)
{
    made_shot = t;
}
