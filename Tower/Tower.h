/*
* FILNAMN:          Tower.h
* PROGRAMMERARE:    Pontus Erlesand   910117-1172, Y3a
                    Karin Lockowandt  910213-3262, Yi3
* DATUM:            2013-mm-dd
*
* BESKRIVNING
*
*
*/





#ifndef TOWER_H
#define TOWER_H
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Sheep.h"
#include "Shot.h"
using namespace std;

/*
struct pos
{
    int x_pos = 0;
    int y_pos = 0;
};


/*
    Basklass f�r torn
*/
class Tower
{
protected:
    int range;
    int shooting_speed; // i sekunder
    int dmg;
    pos T_pos;
    int current_graphic_state;

public:
    Tower(int,int,int,pos);
<<<<<<< HEAD
   virtual void locate_sheep();
    void shoot(Sheep&);

=======
    virtual void locate_sheep(Sheep);
    void shoot(Sheep);
    pos get_position();
    virtual sf::Sprite get_Tower_Sprite() = 0;
>>>>>>> 8f263b5a4bbab335fd61068219ec2dff058f4214


};


class Catapult_tower : public Tower
{
public:
    Catapult_tower(pos);
    sf::Sprite get_Tower_Sprite();

private:
    sf::Sprite Tower_Sprite;
    int current_graphic_state = 1;

};

class Shooting_tower : public Tower
{
public:
    Shooting_tower(pos);
    sf::Sprite get_Tower_Sprite();

private:
    sf::Sprite Tower_Sprite;
    int current_graphic_state = 1;
};


inline void mytimer(clock_t sec) //en funktion som f�rdr�jer skotten i sec-antal sekunder
{
    clock_t start_time = clock();
    clock_t end_time = sec*1000 + start_time;
    while(clock() != end_time);
}





#endif // TOWER_H
