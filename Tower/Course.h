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

    pos wp0{-5, 10}; //-5 är utanför den synliga banan
    pos wp1{20, 10};
    pos wp2{20, 80};
    pos wp3{50, 80};
    pos wp4{50, 60};
    pos wp5{70, 60};
    pos wp6{70, 120}; //120 är utanför den synliga banan banan

    sf::Rect<int> r0{sf::Rect<int>(1,2,3,4)};
    sf::Rect<int> r1{sf::Rect<int>(1,2,3,4)};
    sf::Rect<int> r2{sf::Rect<int>(1,2,3,4)};
    sf::Rect<int> r3{sf::Rect<int>(1,2,3,4)};
    sf::Rect<int> r4{sf::Rect<int>(1,2,3,4)};
    sf::Rect<int> r5{sf::Rect<int>(1,2,3,4)};

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
