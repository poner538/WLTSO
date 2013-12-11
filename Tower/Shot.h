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
#include <iostream>
#include "Sheep.h"


/*
  struct pos
    {
        int x_pos = 0;
        int y_pos = 0;
        int waypoint_number = 0;
    };


//dummyfår för att testa shot
/*
class Sheep
{
    pos current_position;

   public:
       Sheep();
       int hp;
    pos get_position()
    {
        return current_position;
    }

   void hit(int);
};

/*

Klassen Shot ska tilldelas ett får, en skada den ska göra och en startposition

*/


class Shot
{
    public:
    Shot(Sheep,int,pos);
    ~Shot();
//    ~Shot(Sheep);
    int get_dmg();
    void hunt_sheep();


    private:
    int dmg;
    pos shot_pos;
    Sheep target;
    //sf::Image ShotImage(".jpg");
    //sf::Sprite ShotSprite(ShotImage);
    void hit_sheep();

};












#endif
