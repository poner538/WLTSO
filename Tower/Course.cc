/*
 * FILNAMN:       Course.cc
 * PROGRAMMERARE: Daniel Brattgård 900926-3394, Y3a
 *                Marie Ekbrant 890401-2740, Y3a
 * DATUM:         2013-12-09
 *
 * BESKRIVNING
 *
 * Hur fåren ska flytta sig under spelet
 */

#include "Course.h"
#include <vector>
#include <iostream>

Course::Course()
{
    initiate_rectangles();
    Rect0_Sprite.setTexture(TextureHandler::texturehandler.getCourse());
    Rect1_Sprite.setTexture(TextureHandler::texturehandler.getCourse());
    Rect2_Sprite.setTexture(TextureHandler::texturehandler.getCourse());
    Rect3_Sprite.setTexture(TextureHandler::texturehandler.getCourse());
    Rect4_Sprite.setTexture(TextureHandler::texturehandler.getCourse());
    Rect5_Sprite.setTexture(TextureHandler::texturehandler.getCourse());
    Rect0_Sprite.setTextureRect(r0);
    Rect1_Sprite.setTextureRect(r1);
    Rect2_Sprite.setTextureRect(r2);
    Rect3_Sprite.setTextureRect(r3);
    Rect4_Sprite.setTextureRect(r4);
    Rect5_Sprite.setTextureRect(r5);
}

//Hämtar rätt Sprite till rätt rektangel
sf::Sprite Course::get_Course_Sprite(int number)
{
    if (number == 0)
    {
        return Rect0_Sprite;
    }
    else if (number == 1)
    {
        return Rect1_Sprite;
    }
    else if (number == 2)
    {
        return Rect2_Sprite;
    }
    else if (number == 3)
    {
        return Rect3_Sprite;
    }
    else if (number == 4)
    {
        return Rect4_Sprite;
    }
    else if (number == 5)
    {
        return Rect5_Sprite;
    }
}

//Definierar de rektanglar som banan består av
void Course::initiate_rectangles()
{
    int spread = 30; //T.ex.
    r0 = sf::Rect<int>{sf::Rect<int>(wp0.x_pos - spread, wp0.y_pos - spread, wp1.x_pos - wp0.x_pos + 2*spread, 2*spread)}; //Hårdkodat med riktningar och sånt +- ema
    r1 = sf::Rect<int>{sf::Rect<int>(wp1.x_pos - spread, wp1.y_pos - spread, 2*spread, wp2.y_pos - wp1.y_pos + 2*spread)};
    r2 = sf::Rect<int>{sf::Rect<int>(wp2.x_pos - spread, wp2.y_pos - spread, wp3.x_pos - wp2.x_pos + 2*spread, 2*spread)};
    r3 = sf::Rect<int>{sf::Rect<int>(wp4.x_pos - spread, wp4.y_pos - spread, 2*spread, wp3.y_pos - wp4.y_pos + 2*spread)};
    r4 = sf::Rect<int>{sf::Rect<int>(wp4.x_pos - spread, wp4.y_pos - spread, wp5.x_pos - wp4.x_pos + 2*spread, 2*spread)};
    r5 = sf::Rect<int>{sf::Rect<int>(wp5.x_pos - spread, wp5.y_pos - spread, 2*spread, wp6.y_pos - wp5.y_pos + 2*spread)};

    Rect0_Sprite.setPosition(wp0.x_pos - spread, wp0.y_pos - spread);
    Rect1_Sprite.setPosition(wp1.x_pos - spread, wp1.y_pos - spread);
    Rect2_Sprite.setPosition(wp2.x_pos - spread, wp2.y_pos - spread);
    Rect3_Sprite.setPosition(wp4.x_pos - spread, wp4.y_pos - spread);
    Rect4_Sprite.setPosition(wp4.x_pos - spread, wp4.y_pos - spread);
    Rect5_Sprite.setPosition(wp5.x_pos - spread, wp5.y_pos - spread);
}

//Hämtar rätt waypoint
pos Course::get_waypoint(int number)
{
    if (number == 0)
    {
        return wp0;
    }
    else if (number == 1)
    {
        return wp1;
    }
    else if (number == 2)
    {
        return wp2;
    }
    else if (number == 3)
    {
        return wp3;
    }
    else if (number == 4)
    {
        return wp4;
    }
    else if (number == 5)
    {
        return wp5;
    }
    else if (number == 6)
    {
        return wp6;
    }
}

//Hämtar rätt rektangel
sf::Rect<int> Course::get_Rect(int number)
{
    if (number == 0)
    {
        return r0;
    }
    else if (number == 1)
    {
        return r1;
    }
    else if (number == 2)
    {
        return r2;
    }
    else if (number == 3)
    {
        return r3;
    }
    else if (number == 4)
    {
        return r4;
    }
    else if (number == 5)
    {
        return r5;
    }
}

