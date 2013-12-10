/*
* FILNAMN:          Shot.cc
* PROGRAMMERARE:    Pontus Erlesand   910117-1172, Y3a
                    Karin Lockowandt  910213-3262, Yi3
* DATUM:            2013-mm-dd
*
* BESKRIVNING
*
*
*/


#include <SFML/Graphics.hpp>
#include "Shot.h"
#include <iostream>
#include <math.h>

Shot::Shot(Sheep sheep_target, int new_dmg,pos start_pos)
{
    target = sheep_target;
    dmg = new_dmg;
    shot_pos = start_pos;
}

Shot::~Shot()
{}

void Shot::hunt_sheep()
{
    if((target.get_position().x_pos == shot_pos.x_pos) and (target.get_position().y_pos == shot_pos.y_pos))
    {
        hit_sheep();
        return;
    }
    else
    {
        if(target.get_position().x_pos < shot_pos.x_pos)
        {
            std::cout << "x-\n";
            --shot_pos.x_pos;
        }
        else if(target.get_position().x_pos > shot_pos.x_pos)
        {
            ++shot_pos.x_pos;
        }
        if(target.get_position().y_pos < shot_pos.y_pos)
        {
            std::cout << "y-\n";
            --shot_pos.y_pos;
        }
        else if(target.get_position().y_pos > shot_pos.y_pos)
        {
            ++shot_pos.y_pos;
        }
    }
    hunt_sheep();
}

void Shot::hit_sheep()
{
    target.hit(dmg);
    delete this;
}


//dummies för sheepdumme att testa Shot här nedanför
/*
Sheep::Sheep()
{
    dmg = 10;
}

void Sheep::hit(int damage)
   {

       if(dmg < damage)
       {
        std::cout << "dödat får\n";
         delete this;
       }
       else
        std::cout << "nästan dödat får\n";
        {
        this->dmg = dmg - damage;
        return;
        }
   }
*/
