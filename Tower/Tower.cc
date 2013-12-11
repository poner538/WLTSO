/*
* FILNAMN:          Tower.cc
* PROGRAMMERARE:    Pontus Erlesand   910117-1172, Y3a
                    Karin Lockowandt  910213-3262, Yi3
* DATUM:            2013-mm-dd
*
* BESKRIVNING
*
*
*/


//#include "Sheep.h"
#include <SFML/Graphics.hpp>
#include "Tower.h"
#include <iostream>
#include <math.h>


using namespace std;

Tower::Tower(int new_range,int new_shooting_speed,int new_dmg,pos new_pos)
{
    dmg = new_dmg;
    shooting_speed = new_shooting_speed;
    range = new_range;
    T_pos = new_pos;
}

Catapult_tower::Catapult_tower(pos new_pos)
    : Tower(100,2,7,new_pos)
{
}

sf::Sprite Catapult_tower::get_Tower_Sprite()
{
    return Tower_Sprite;
}

Shooting_tower::Shooting_tower(pos new_pos)
    : Tower(15,1,5,new_pos)
{
}

sf::Sprite Shooting_tower::get_Tower_Sprite()
{
    return Tower_Sprite;
}

void Tower::locate_sheep(Sheep vec_sheep)
{



        if ( pow(range, 2) >= pow((vec_sheep.get_position().x_pos - T_pos.x_pos),2) + pow((vec_sheep.get_position().y_pos + T_pos.y_pos),2)) //and x = sheep_posx and y = sheep_posy)
        {
             cout << "hittade fåret\n";
            shoot(vec_sheep);

            return;
        }
        else
        {
            //mytimer(5);
            cout << "hitta inget får \n";
        }

}


void Tower::shoot(Sheep sheep_target)
{
    Shot a_shot(sheep_target,dmg,T_pos);
    a_shot.hunt_sheep();
    mytimer(shooting_speed);
}

pos Tower::get_position()
{
    return T_pos;
}


