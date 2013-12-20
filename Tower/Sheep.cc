/*
* FILNAMN:          Sheep.cc
* PROGRAMMERARE:    Johanna Laidla  910712-5826, Y3a
*                   Ema Becirovic   920510-6249, Y3a
* DATUM:            2013-12-19
*
* BESKRIVNING
*
* Classer och subklasser för alla får,
* med tillhörande funktioner för hur de ska röra sig längs banan och vad
* de ska göra när de blir träffade och dör.
*
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Sheep.h"
#include <cmath>
#include <iostream>

Sheep::Sheep(int new_speed, int new_hp, int new_bounty, Course new_Course)
{
    speed = new_speed;
    hp = new_hp;
    bounty = new_bounty;
    current_Course = new_Course;
}

/* När ett får blir träffat förlorar det hp, mängd guld och poäng ökar */
void Sheep::hit(int damage)
{
    hp = hp - damage;
    if (hp <= 0)
    {
        Controller::controller.change_gold(bounty);
        Controller::controller.change_points(bounty);
        change_death(true);
    }
}

/* */
float Sheep::get_distance()
{
    return distance;
}

/* Kollar om ett får är dött eller ej */
bool Sheep::get_death()
{
    return am_I_dead;
}

/* Ändrar fårets livsstatus till död */
void Sheep::change_death(bool t)
{
    am_I_dead = t;
}

/*EasySheep*/
EasySheep::EasySheep(Course new_Course) : Sheep (150/*speed*/, 100/*hp*/, 12/*bounty*/, new_Course)
{
    Sheep_Sprite.setTexture(TextureHandler::texturehandler.getEasySheep());
    set_position(current_position);
}

/* Returnerar fårets position */
pos EasySheep::get_position()
{
    return current_position;
}

/* Ändrar fårets position */
void EasySheep::set_position(pos new_position)
{
    current_position = new_position;
    Sheep_Sprite.setPosition(new_position.x_pos - 20, new_position.y_pos - 20);
}

/* Returnerar fårets Sprite */
sf::Sprite EasySheep::get_Sheep_Sprite()
{
    return Sheep_Sprite;
}

bool EasySheep::update_position(float time)
{
    float x_temp = 0;
    float y_temp = 0;
    float norm = 0;
    float way_to_next = 0;
    pos temp_pos;
    x_temp = next_position.x_pos - current_position.x_pos;
    y_temp = next_position.y_pos - current_position.y_pos;
    norm = sqrt(pow(x_temp, 2) + pow(y_temp, 2));
    if(time*speed >= norm)
    {
        if (next_waypoint == 6)//då har den gått i mål
        {
            Controller::controller.lives();
            change_death(true);
            return true;
        }
        x_temp = x_temp / norm;
        y_temp = y_temp / norm;
        temp_pos.x_pos = current_position.x_pos + x_temp*(time*speed-norm);
        temp_pos.y_pos = current_position.y_pos + y_temp*(time*speed-norm);
        way_to_next = 2*norm - time*speed;
        next_position = current_Course.get_waypoint(next_waypoint+1);
        next_waypoint = next_waypoint + 1;

        set_position(temp_pos);

        //Här har den kommit till waypointens position och ska vidare
        x_temp = next_position.x_pos - current_position.x_pos;
        y_temp = next_position.y_pos - current_position.y_pos;
        norm = sqrt(pow(x_temp, 2) + pow(y_temp, 2));
        x_temp = x_temp / norm;
        y_temp = y_temp / norm;
        temp_pos.x_pos = current_position.x_pos + x_temp*way_to_next;
        temp_pos.y_pos = current_position.y_pos + y_temp*way_to_next;
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
    return false;
}

/*MediumSheep*/
MediumSheep::MediumSheep(Course new_Course) : Sheep (225/*speed*/, 200/*hp*/, 24/*bounty*/, new_Course)
{
    Sheep_Sprite.setTexture(TextureHandler::texturehandler.getMediumSheep());
    set_position(current_position);

}

pos MediumSheep::get_position()
{
    return current_position;
}

void MediumSheep::set_position(pos new_position)
{
    current_position = new_position;
    Sheep_Sprite.setPosition(new_position.x_pos - 20, new_position.y_pos - 20);
}

sf::Sprite MediumSheep::get_Sheep_Sprite()
{
    return Sheep_Sprite;
}

bool MediumSheep::update_position(float time)
{
    float x_temp = 0;
    float y_temp = 0;
    float norm = 0;
    float way_to_next = 0;
    pos temp_pos;
    x_temp = next_position.x_pos - current_position.x_pos;
    y_temp = next_position.y_pos - current_position.y_pos;
    norm = sqrt(pow(x_temp, 2) + pow(y_temp, 2));
    if(time*speed >= norm)
    {
        if (next_waypoint == 6)//då har den gått i mål
        {
            Controller::controller.lives();
            change_death(true);
            return true;
        }
        x_temp = x_temp / norm;
        y_temp = y_temp / norm;
        temp_pos.x_pos = current_position.x_pos + x_temp*(time*speed-norm);
        temp_pos.y_pos = current_position.y_pos + y_temp*(time*speed-norm);
        way_to_next = 2*norm - time*speed;
        next_position = current_Course.get_waypoint(next_waypoint+1);
        next_waypoint = next_waypoint + 1;

        set_position(temp_pos);

        //H�r har den kommit till waypointens position och ska vidare
        x_temp = next_position.x_pos - current_position.x_pos;
        y_temp = next_position.y_pos - current_position.y_pos;
        norm = sqrt(pow(x_temp, 2) + pow(y_temp, 2));
        x_temp = x_temp / norm;
        y_temp = y_temp / norm;
        temp_pos.x_pos = current_position.x_pos + x_temp*way_to_next;
        temp_pos.y_pos = current_position.y_pos + y_temp*way_to_next;
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
    return false;
}

/*HardSheep*/
HardSheep::HardSheep(Course new_Course) : Sheep (300/*speed*/, 300/*hp*/, 36/*bounty*/, new_Course)
{
    Sheep_Sprite.setTexture(TextureHandler::texturehandler.getHardSheep());
    set_position(current_position);
}

pos HardSheep::get_position()
{
    return current_position;
}

void HardSheep::set_position(pos new_position)
{
    current_position = new_position;
    Sheep_Sprite.setPosition(new_position.x_pos - 20, new_position.y_pos - 20);
}

sf::Sprite HardSheep::get_Sheep_Sprite()
{
    return Sheep_Sprite;
}

bool HardSheep::update_position(float time)
{
    float x_temp = 0;
    float y_temp = 0;
    float norm = 0;
    float way_to_next = 0;
    pos temp_pos;
    x_temp = next_position.x_pos - current_position.x_pos;
    y_temp = next_position.y_pos - current_position.y_pos;
    norm = sqrt(pow(x_temp, 2) + pow(y_temp, 2));
    if(time*speed >= norm)
    {
        if (next_waypoint == 6)//d� har den g�tt i m�l
        {
            Controller::controller.lives();
            change_death(true);
            return true;
        }
        x_temp = x_temp / norm;
        y_temp = y_temp / norm;
        temp_pos.x_pos = current_position.x_pos + x_temp*(time*speed-norm);
        temp_pos.y_pos = current_position.y_pos + y_temp*(time*speed-norm);
        way_to_next = 2*norm - time*speed;
        next_position = current_Course.get_waypoint(next_waypoint+1);
        next_waypoint = next_waypoint + 1;

        set_position(temp_pos);

        //H�r har den kommit till waypointens position och ska vidare
        x_temp = next_position.x_pos - current_position.x_pos;
        y_temp = next_position.y_pos - current_position.y_pos;
        norm = sqrt(pow(x_temp, 2) + pow(y_temp, 2));
        x_temp = x_temp / norm;
        y_temp = y_temp / norm;
        temp_pos.x_pos = current_position.x_pos + x_temp*way_to_next;
        temp_pos.y_pos = current_position.y_pos + y_temp*way_to_next;
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
    return false;


}

/*BossSheep*/
BossSheep::BossSheep(Course new_Course) : Sheep (100/*speed*/, 20000/*hp*/, 1337/*bounty*/, new_Course)
{
    Sheep_Sprite.setTexture(TextureHandler::texturehandler.getBossSheep());
    set_position(current_position);
}

pos BossSheep::get_position()
{
    return current_position;
}

void BossSheep::set_position(pos new_position)
{
    current_position = new_position;
    Sheep_Sprite.setPosition(new_position.x_pos - 80, new_position.y_pos - 100);
}

sf::Sprite BossSheep::get_Sheep_Sprite()
{
    return Sheep_Sprite;
}

bool BossSheep::update_position(float time)
{
    float x_temp = 0;
    float y_temp = 0;
    float norm = 0;
    float way_to_next = 0;
    pos temp_pos;
    x_temp = next_position.x_pos - current_position.x_pos;
    y_temp = next_position.y_pos - current_position.y_pos;
    norm = sqrt(pow(x_temp, 2) + pow(y_temp, 2));
    if(time*speed >= norm)
    {
        if (next_waypoint == 6)//d� har den g�tt i m�l
        {
            Controller::controller.lives();
            change_death(true);
            return true;
        }
        x_temp = x_temp / norm;
        y_temp = y_temp / norm;
        temp_pos.x_pos = current_position.x_pos + x_temp*(time*speed-norm);
        temp_pos.y_pos = current_position.y_pos + y_temp*(time*speed-norm);
        way_to_next = 2*norm - time*speed;
        next_position = current_Course.get_waypoint(next_waypoint+1);
        next_waypoint = next_waypoint + 1;

        set_position(temp_pos);

        //H�r har den kommit till waypointens position och ska vidare
        x_temp = next_position.x_pos - current_position.x_pos;
        y_temp = next_position.y_pos - current_position.y_pos;
        norm = sqrt(pow(x_temp, 2) + pow(y_temp, 2));
        x_temp = x_temp / norm;
        y_temp = y_temp / norm;
        temp_pos.x_pos = current_position.x_pos + x_temp*way_to_next;
        temp_pos.y_pos = current_position.y_pos + y_temp*way_to_next;
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
    return false;
}
