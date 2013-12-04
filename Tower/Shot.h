/*
* FILNAMN:          Shot.h
* PROGRAMMERARE:    Pontus Erlesand   910117-1172, Y3a
                    Karin Lockowandt  910213-3262, Yi3
* DATUM:            2013-mm-dd
*
* BESKRIVNING
*
*
*/

#ifndef SHOT_H
#define SHOT_H
#include <SFML/Graphics.hpp>

struct pos
{
    int x_pos = 0;
    int y_pos = 0;
    int waypoint_number = 0;
};


class Shot
{
    public:
    Shot(Sheep , int);
    ~Shot();
    ~Shot(Sheep);
    private:
    int dmg;
    pos shot_pos;
    Sheep target;
    //sf::Image ShotImage(".jpg");
    //sf::Sprite ShotSprite(ShotImage);
    void hit_sheep();
    void hunt_sheep();
};





#endif
