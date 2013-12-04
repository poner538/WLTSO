#include <SFML/Graphics.hpp>
#include "Tower.h"
#include <iostream>
#include <math.h>


using namespace std;

Tower::Tower(int new_range,int new_shooting_speed,int new_dmg)
{
    dmg = new_dmg;
    shooting_speed = new_shooting_speed;
    range = new_range;
}
/*
Catapult_tower::Catapult_tower(int new_range,int new_shooting_speed,int new_dmg)
    :Tower(new_range,new_shooting_speed,new_dmg)
    {
    }
*/
Catapult_tower::Catapult_tower()
    //:Tower(10,10,5)
{
    dmg = 10;
    shooting_speed = 10;
    range = 5;
}

Shooting_tower::Shooting_tower()
    :Tower(15,29,32)
{

}

void Tower::locate_sheep()
{
    posx = 100;
    posy = 50;
    int x = 120;
    int y = 50;

        if ( pow(range, 2) >= pow((x - posx),2) + pow((y - posy),2)) //and x = sheep_posx and y = sheep_posy)
        {

            //shoot();
            cout << "hittade fåret\n";

        }
        else
        {
            mytimer(5);
            cout << "hitta inget\n";
        }

}

/*
void Tower::shoot(Sheep sheep_target)
{
    Shot(dmg,sheep_target);
    mytimer(shooting_speed);
}
*/

