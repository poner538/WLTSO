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

Catapult_tower::Catapult_tower(pos new_pos) :Tower(10,10,5,new_pos)
{
}

Shooting_tower::Shooting_tower(pos new_pos) :Tower(15,29,32,new_pos)
{
}

void Tower::locate_sheep()
{

    int x = 120;
    int y = 50;

        if ( pow(range, 2) >= pow((x - T_pos.x_pos),2) + pow((y + T_pos.y_pos),2)) //and x = sheep_posx and y = sheep_posy)
        {

            //shoot();
            cout << "hittade fåret\n";

        }
        else
        {
            //mytimer(5);
            cout << "hitta inget skott \n";
        }

}

/*
void Tower::shoot(Sheep sheep_target)
{
    Shot a_shot(sheep_target,dmg,);
    a_shot.hunt_sheep();
    mytimer(shooting_speed);
}
*/

