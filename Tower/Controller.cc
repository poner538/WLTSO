/*
* FILNAMN:          Controller.cc
* PROGRAMMERARE:    Johanna Laidla  910712-5826, Y3a
                    Ema Becirovic   920510-6249, Y3a
* DATUM:            2013-mm-dd
*
* BESKRIVNING
*
*
*/

#include "Controller.h"
#include <iostream>

Controller Controller::controller(100,100);

Controller::Controller(int new_gold, int new_lives)
{
    gold = new_gold;
    current_lives = new_lives;
    points = 0;
}

void Controller::change_gold(const int value)
{
    if ((gold + value) < 0)
    {
        cout<<"Du är för fattig för att köpa torn!"<<endl; //Ville göra en popup som går att stänga. #varningsmeddelande
    }
    gold = gold + value;
}

void Controller::change_points(const int value)
{
    points = points + value;
}

void Controller::lives()
{
    if (current_lives == 1)
    {
        //Game.GameOver() kanske det kan heta
    }
    current_lives = current_lives - 1;
}
