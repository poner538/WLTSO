/*
* FILNAMN:          Course.h
* PROGRAMMERARE:    Johanna Laidla      910712-5826, Y3a
                    Ema Becirovic       920510-6249, Y3a
                    Karin Lockowandt    910213-3260, Yi3
                    Daniel Brattgård    900926-3394, Y3a
                    Pontus Erlesand     910117-1172, Y3a
                    Marie Ekbrant       890401-2740, Y3a
* DATUM:            2013-12-19
*
* Headerfil till klassen Course;
*
*/
#ifndef COURSE_H
#define COURSE_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "TextureHandler.h"

/* En egengjord struktur för positionering av objekt */
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
    Course();
    ~Course() = default; //Destruktor
    pos get_waypoint(int);
    void waypoint_direction(int);
    sf::Sprite get_Course_Sprite(int);
    sf::Rect<int> get_Rect(int);

private:
   void initiate_rectangles();

    sf::Sprite Rect0_Sprite;
    sf::Sprite Rect1_Sprite;
    sf::Sprite Rect2_Sprite;
    sf::Sprite Rect3_Sprite;
    sf::Sprite Rect4_Sprite;
    sf::Sprite Rect5_Sprite;

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

 };

 #endif //COURSE_H
