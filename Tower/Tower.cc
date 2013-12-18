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

Tower::Tower(int new_range,float new_shooting_speed,int new_dmg,pos new_pos,Board* new_Board)
{
    dmg = new_dmg;
    shooting_speed = new_shooting_speed;
    range = new_range;
    T_pos = new_pos;
    GameBoard = new_Board;
}

Catapult_tower::Catapult_tower(pos new_pos,Board* new_Board)

    : Tower(232,0.15,350,new_pos,new_Board)

{
    Tower_Sprite.setTexture(TextureHandler::texturehandler.getCatapult_tower());
    Tower_Sprite.setPosition(new_pos.x_pos,new_pos.y_pos);
}

sf::Sprite Catapult_tower::get_Tower_Sprite()
{
    return Tower_Sprite;
}

Shooting_tower::Shooting_tower(pos new_pos,Board* new_Board)
    : Tower(323,0.05,50,new_pos,new_Board)
{
    Tower_Sprite.setTexture(TextureHandler::texturehandler.getShooting_tower());
    Tower_Sprite.setPosition(new_pos.x_pos,new_pos.y_pos);
}

sf::Sprite Shooting_tower::get_Tower_Sprite()
{
    return Tower_Sprite;
}

void Tower::locate_sheep(vector<Sheep*>& vec_sheep,float time)
{
    if(shot_timer(time))
    {
        Sheep* temp_Sheep = vec_sheep.at(0);
        int x = 0;
        for(int i = 0 ; i < vec_sheep.size() ; i++)
        {
            for(int i = 0 ; i < vec_sheep.size() ; i++)
            {
                if (! vec_sheep.at(i)->am_i_dead)
                {
                    if (vec_sheep.at(i)->get_distance() > temp_Sheep->get_distance())
                    {
                        temp_Sheep = vec_sheep.at(i);
                        x = i;
                    }
                }
            }
            if ( pow(range, 2) >= pow((vec_sheep.at(x)->get_position().x_pos - T_pos.x_pos),2) + pow((vec_sheep.at(x)->get_position().y_pos - T_pos.y_pos),2)) //and x = sheep_posx and y = sheep_posy)
            {
                shoot(vec_sheep.at(x));
                Controller::controller.made_shot = true;
                return;
            }
        }
    }
}

void Tower::shoot(Sheep*& sheep_target)
{
    Shot* a_shot = new Shot(sheep_target, dmg, T_pos);
    GameBoard->set_Shot(a_shot);
}

pos Tower::get_position()
{
    return T_pos;
}

bool Tower::shot_timer(float time) //en funktion som fördröjer skotten i sec-antal sekunder
{
    if(temptime >= shooting_speed)
    {
        temptime = 0;
        return true;
    }
    else
    {

        temptime = temptime + time/10;
        return false;
    }
}

