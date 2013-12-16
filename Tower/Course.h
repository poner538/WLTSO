/*
 * FILNAMN:       Course.h
 * PROGRAMMERARE: Daniel Brattgård 900926-3394, Y3a
 *                Marie Ekbrant 890401-2740, Y3a
 * DATUM:         2013-12-09
 *
 * BESKRIVNING
 *
 * Hur fåren ska flytta sig under spelet
 */

#ifndef COURSE_H
#define COURSE_H

#include <vector> //Det som behövs
#include <SFML/Graphics.hpp> //Användning av SFMLs rektangelfkn
#include "TextureHandler.h"


struct pos
{
    int x_pos = 0;
    int y_pos = 0;
    pos(int x = 0, int y = 0)
    {
        x_pos = x;
        y_pos = y;
    }
};

class Course
{
public:

	Course(/*vector <pos> waypoints (pos0, pos1, pos2, pos3, pos4, pos5*/);
    ~Course() = default; //Destruktor
    pos get_waypoint(int);
    void waypoint_direction(int);
    sf::Sprite get_Course_Sprite(int);


    pos wp0{-20, 60}; //-20 är utanför den synliga banan
    pos wp1{120, 60};
    pos wp2{120, 480};
    pos wp3{300, 480};
    pos wp4{300, 360};
    pos wp5{420, 360};
    pos wp6{420, 620}; //620 är utanför den synliga banan


    sf::Rect<int> r0{sf::Rect<int>(0,0,0,0)};
    sf::Rect<int> r1{sf::Rect<int>(0,0,0,0)};
    sf::Rect<int> r2{sf::Rect<int>(0,0,0,0)};
    sf::Rect<int> r3{sf::Rect<int>(0,0,0,0)};
    sf::Rect<int> r4{sf::Rect<int>(0,0,0,0)};
    sf::Rect<int> r5{sf::Rect<int>(0,0,0,0)};

private:
   void initiate_rectangles();

    sf::Sprite Rect0_Sprite;
    sf::Sprite Rect1_Sprite;
    sf::Sprite Rect2_Sprite;
    sf::Sprite Rect3_Sprite;
    sf::Sprite Rect4_Sprite;
    sf::Sprite Rect5_Sprite;

 };

 #endif //COURSE_H
