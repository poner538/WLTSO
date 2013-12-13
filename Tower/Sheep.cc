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
#include <cmath>

Sheep::Sheep(int new_speed, int new_hp, int new_bounty, Course new_Course)
{
    speed = new_speed;
    hp = new_hp;
    bounty = new_bounty;
    current_Course = new_Course;
}

void Sheep::hit(int damage)
{
    if (damage > hp)  //Kanske >=, lever inte fåret på 0 hp nu?
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

float Sheep::get_distance()
{
    return distance;
}

/*EasySheep*/

EasySheep::EasySheep(Course new_Course) : Sheep (1/*speed*/, 100/*hp*/, 6/*bounty*/, new_Course)
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
}

sf::Sprite EasySheep::get_Sheep_Sprite()
{
    return Sheep_Sprite;
}

void EasySheep::update_position(float time)
{
    float x_temp = 0;
    float y_temp = 0;
    float norm = 0;
    pos temp_pos;
    x_temp = next_position.x_pos - current_position.x_pos;
    y_temp = next_position.y_pos - current_position.y_pos;
    norm = sqrt(pow(x_temp, 2) + pow(y_temp, 2));
    if(time*speed >= norm)
    {
        if (next_waypoint = 5)//då har den gått i mål
        {
            Controller::controller.lives();
            delete this;

        }

        x_temp = x_temp / norm;
        y_temp = y_temp / norm;
        temp_pos.x_pos = current_position.x_pos + x_temp*(time*speed-norm);
        temp_pos.y_pos = current_position.y_pos + y_temp*(time*speed-norm);

        next_position = current_Course.get_waypoint(next_waypoint+1);
        next_waypoint = next_waypoint + 1;

        set_position(temp_pos);

        //Här har den kommit till waypointens position och ska vidare
        x_temp = next_position.x_pos - current_position.x_pos;
        y_temp = next_position.y_pos - current_position.y_pos;
        norm = sqrt(pow(x_temp, 2) + pow(y_temp, 2));
        x_temp = x_temp / norm;
        y_temp = y_temp / norm;
        temp_pos.x_pos = current_position.x_pos + x_temp*(norm - time*speed);
        temp_pos.y_pos = current_position.y_pos + y_temp*(norm - time*speed);

        set_position(temp_pos);
    }
    else
    {
        x_temp = x_temp / norm;
        y_temp = y_temp / norm;
        temp_pos.x_pos = current_position.x_pos + x_temp*time*speed;
        temp_pos.y_pos = current_position.y_pos + y_temp*time*speed;

        set_position(temp_pos);
    }
    distance = distance + time*speed;
}

/*MediumSheep*/

MediumSheep::MediumSheep(Course new_Course) : Sheep (2/*speed*/, 200/*hp*/, 12/*bounty*/, new_Course)
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
}

sf::Sprite MediumSheep::get_Sheep_Sprite()
{
    return Sheep_Sprite;
}

void MediumSheep::update_position(float time)
{
    float x_temp = 0;
    float y_temp = 0;
    float norm = 0;
    pos temp_pos;
    x_temp = next_position.x_pos - current_position.x_pos;
    y_temp = next_position.y_pos - current_position.y_pos;
    norm = sqrt(pow(x_temp, 2) + pow(y_temp, 2));
    if(time*speed >= norm)
    {
        if (next_waypoint = 5)//då har den gått i mål
        {
            Controller::controller.lives();
            delete this;

        }

        x_temp = x_temp / norm;
        y_temp = y_temp / norm;
        temp_pos.x_pos = current_position.x_pos + x_temp*(time*speed-norm);
        temp_pos.y_pos = current_position.y_pos + y_temp*(time*speed-norm);

        next_position = current_Course.get_waypoint(next_waypoint+1);
        next_waypoint = next_waypoint + 1;

        set_position(temp_pos);

        //Här har den kommit till waypointens position och ska vidare
        x_temp = next_position.x_pos - current_position.x_pos;
        y_temp = next_position.y_pos - current_position.y_pos;
        norm = sqrt(pow(x_temp, 2) + pow(y_temp, 2));
        x_temp = x_temp / norm;
        y_temp = y_temp / norm;
        temp_pos.x_pos = current_position.x_pos + x_temp*(norm - time*speed);
        temp_pos.y_pos = current_position.y_pos + y_temp*(norm - time*speed);

        set_position(temp_pos);
    }
    else
    {
        x_temp = x_temp / norm;
        y_temp = y_temp / norm;
        temp_pos.x_pos = current_position.x_pos + x_temp*time*speed;
        temp_pos.y_pos = current_position.y_pos + y_temp*time*speed;

        set_position(temp_pos);
    }
    distance = distance + time*speed;
}

/*HardSheep*/

HardSheep::HardSheep(Course new_Course) : Sheep (3/*speed*/, 300/*hp*/, 18/*bounty*/, new_Course)
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
}

sf::Sprite HardSheep::get_Sheep_Sprite()
{
    return Sheep_Sprite;
}

void HardSheep::update_position(float time)
{
    float x_temp = 0;
    float y_temp = 0;
    float norm = 0;
    pos temp_pos;
    x_temp = next_position.x_pos - current_position.x_pos;
    y_temp = next_position.y_pos - current_position.y_pos;
    norm = sqrt(pow(x_temp, 2) + pow(y_temp, 2));
    if(time*speed >= norm)
    {
        if (next_waypoint = 5)//då har den gått i mål
        {
            Controller::controller.lives();
            delete this;

        }

        x_temp = x_temp / norm;
        y_temp = y_temp / norm;
        temp_pos.x_pos = current_position.x_pos + x_temp*(time*speed-norm);
        temp_pos.y_pos = current_position.y_pos + y_temp*(time*speed-norm);

        next_position = current_Course.get_waypoint(next_waypoint+1);
        next_waypoint = next_waypoint + 1;

        set_position(temp_pos);

        //Här har den kommit till waypointens position och ska vidare
        x_temp = next_position.x_pos - current_position.x_pos;
        y_temp = next_position.y_pos - current_position.y_pos;
        norm = sqrt(pow(x_temp, 2) + pow(y_temp, 2));
        x_temp = x_temp / norm;
        y_temp = y_temp / norm;
        temp_pos.x_pos = current_position.x_pos + x_temp*(norm - time*speed);
        temp_pos.y_pos = current_position.y_pos + y_temp*(norm - time*speed);

        set_position(temp_pos);
    }
    else
    {
        x_temp = x_temp / norm;
        y_temp = y_temp / norm;
        temp_pos.x_pos = current_position.x_pos + x_temp*time*speed;
        temp_pos.y_pos = current_position.y_pos + y_temp*time*speed;

        set_position(temp_pos);
    }
    distance = distance + time*speed;
}
