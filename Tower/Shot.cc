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

Shot::Shot(Sheep* sheep_target,const int new_dmg,pos start_pos)
{
    target = sheep_target;
    dmg = new_dmg;
    shot_pos = start_pos;
    speed = 20;
}

Shot::~Shot()
{}

void Shot::hunt_sheep(float time)
{
    float x_temp = shot_pos.x_pos;
    float y_temp = shot_pos.y_pos;
    float norm = 0;
    pos temp_pos;
    x_temp = target.get_position().x_pos - shot_pos.x_pos;
    y_temp = target.get_position().y_pos - shot_pos.y_pos;
    norm = sqrt(pow(x_temp, 2) + pow(y_temp, 2));

    if(time*speed >= norm)
    {
        hit_sheep();
        return;
    }
    else
    {
        x_temp = x_temp / norm;
        y_temp = y_temp / norm;
        shot_pos.x_pos = shot_pos.x_pos + x_temp*(time*speed - norm);
        shot_pos.y_pos = shot_pos.y_pos + y_temp*(time*speed - norm);
    }
//h�r ska vi l�gga till en timer
}




void Shot::hit_sheep()
{
    target->hit(dmg);
    delete this;
}


//dummies f�r sheepdumme att testa Shot h�r nedanf�r
/*
Sheep::Sheep()
{
    hp = 10;
}

void Sheep::hit(const int damage)
   {

       if(hp < damage)
       {
        std::cout << "d�dat f�r\n";
         delete this;
       }
       else
        std::cout << "n�stan d�dat f�r\n";
        {
        this->hp = this->hp - damage;
        std::cout << this->hp << "\n";
        return;
        }
   }

*/
