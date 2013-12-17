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
#include "Sheep.h"
#include "Board.h"
#include <iostream>
#include <math.h>
#include <vector>



using namespace std;

Tower::Tower(int new_range,int new_shooting_speed,int new_dmg,pos new_pos,Board* new_Board)
{
    dmg = new_dmg;
    shooting_speed = new_shooting_speed;
    range = new_range;
    T_pos = new_pos;
    GameBoard = new_Board;
}

Catapult_tower::Catapult_tower(pos new_pos,Board* new_Board)
    : Tower(100,2,7,new_pos,new_Board)
{
    Tower_Sprite.setTexture(TextureHandler::texturehandler.getCatapult_tower());
    Tower_Sprite.setPosition(new_pos.x_pos,new_pos.y_pos);
    Tower_Sprite.setTextureRect(sf::Rect<int>{sf::Rect<int>(new_pos.x_pos, new_pos.y_pos, 50, 50)});
}

sf::Sprite Catapult_tower::get_Tower_Sprite()
{
    return Tower_Sprite;
}

Shooting_tower::Shooting_tower(pos new_pos,Board* new_Board)
    : Tower(15,1,5,new_pos,new_Board)
{
    Tower_Sprite.setTexture(TextureHandler::texturehandler.getShooting_tower());
    Tower_Sprite.setPosition(new_pos.x_pos,new_pos.y_pos);
    Tower_Sprite.setTextureRect(sf::Rect<int>{sf::Rect<int>(new_pos.x_pos, new_pos.y_pos, 50, 50)}); //Detta faqqar texten!
}

sf::Sprite Shooting_tower::get_Tower_Sprite()
{
    return Tower_Sprite;
}

void Tower::locate_sheep(vector<Sheep*> vec_sheep,float time)
{
    if(shot_timer(time))
    {
        temptime = time;
        for(int i = 1 ; i <= vec_sheep.size() ; i++)


            if ( pow(range, 2) >= pow((vec_sheep.at(i)->get_position().x_pos - T_pos.x_pos),2) + pow((vec_sheep.at(i)->get_position().y_pos + T_pos.y_pos),2)) //and x = sheep_posx and y = sheep_posy)
            {
                cout << "hittade fåret\n";
                shoot(vec_sheep.at(i));

                return;
            }
            else
            {
                //mytimer(5);
                cout << "hitta inget får \n";
            }

    }
}

void Tower::shoot(Sheep* sheep_target)
{
    Shot* a_shot = new Shot(sheep_target,dmg,T_pos);
    GameBoard->set_Shot(a_shot);
}

pos Tower::get_position()
{
    return T_pos;
}

bool Tower::shot_timer(float time) //en funktion som fördröjer skotten i sec-antal sekunder
{

    if(time >= temptime + shooting_speed)
        return true;
    else
        return false;

}

