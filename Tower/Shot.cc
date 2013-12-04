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

Shot::Shot(Sheep sheep_target, int new_dmg)
{
    taget = sheep_taget;
    dmg = new_dmg;
}

void Shot::hunt_sheep()
{
    if((target.pos.x_pos == shot_pos.x_pos) and (target.pos.y_pos == shot_pos.y_pos))
    {
        hit_sheep();
    }
    else
    {




    }





}
