#include <iostream>
#include <SFML/Graphics.hpp>

/*
* FILNAMN:          Sheep.cc
* PROGRAMMERARE:    Johanna Laidla  910712-5826, Y3a
                    Ema Becirovic   920510-6249, Y3a
* DATUM:            2013-mm-dd
*
* BESKRIVNING
*
*
*/

#include "Sheep.h"
#include "Controller.h"
#include "TextureHandler.h"

Sheep::Sheep(int new_speed, int new_hp, int new_bounty)
{
    speed = new_speed;
    hp = new_hp;
    bounty = new_bounty;
}

void Sheep::hit(int damage)
{
    if (damage > hp)
    {
        Controller::controller.change_gold(bounty);
        Controller::controller.change_points(bounty);//Eller om vi ska ha datamedlem points
        delete this;
    }
    else
    {
        hp = hp - damage;
    }
}

/*EasySheep*/

EasySheep::EasySheep() : Sheep (1/*speed*/, 100/*hp*/, 6/*bounty*/)
{
    Sheep_Sprite.setTexture(TextureHandler::texturehandler.getEasySheep());
}

pos EasySheep::get_position()
{
    return current_position;
}

void EasySheep::set_position(pos new_position)
{
    current_position = new_position;
    Sheep_Sprite.setPosition(new_position.x_pos, new_position.y_pos);
    current_waypoint = new_position.waypoint_number;
}

sf::Sprite EasySheep::get_Sheep_Sprite()
{
    return Sheep_Sprite;
}

void update_position(float time)
{
    float x_temp = 0;
    float y_temp = 0;
    float norm = 0;
    pos temp_pos;
    x_temp = next_position.x_pos - current_position.x_pos;
    y_temp = next_position.y_pos - current_position.y_pos;
    norm = sqrt(pwr(x_temp, 2) + pwr(y_temp, 2));
    x_temp = x_temp / norm;
    y_temp = y_temp / norm;
    temp_pos.x_pos = current_position.x_pos + x_temp*time*speed;
    temp_pos.y_pos = current_position.y_pos + y_temp*time*speed;
    temp_pos.waypoint_number = current_position.waypoint_number;

    set_position(temp_pos);
}

/*MediumSheep*/

MediumSheep::MediumSheep() : Sheep (2/*speed*/, 200/*hp*/, 12/*bounty*/)
{
    Sheep_Sprite.setTexture(TextureHandler::texturehandler.getMediumSheep());
}

pos MediumSheep::get_position()
{
    return current_position;
}

void MediumSheep::set_position(pos new_position)
{
    current_position = new_position;
    Sheep_Sprite.setPosition(new_position.x_pos, new_position.y_pos);
    current_waypoint = new_position.waypoint_number;
}

sf::Sprite MediumSheep::get_Sheep_Sprite()
{
    return Sheep_Sprite;
}

/*HardSheep*/

HardSheep::HardSheep() : Sheep (3/*speed*/, 300/*hp*/, 18/*bounty*/)
{
    Sheep_Sprite.setTexture(TextureHandler::texturehandler.getHardSheep());
}

pos HardSheep::get_position()
{
    return current_position;
}

void HardSheep::set_position(pos new_position)
{
    current_position = new_position;
    Sheep_Sprite.setPosition(new_position.x_pos, new_position.y_pos);
    current_waypoint = new_position.waypoint_number;
}

sf::Sprite HardSheep::get_Sheep_Sprite()
{
    return Sheep_Sprite;
}
