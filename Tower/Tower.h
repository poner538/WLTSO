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
#include <vector>
#include "Course.h"
#include "Sheep.h"
#include "Shot.h"
#include "Game.h"
#include "Board.h"
using namespace std;


/*
    Basklass för torn
*/
class Tower
{
protected:
    int range;
    int shooting_speed; // i sekunder
    int dmg;
    pos T_pos;
    int current_graphic_state;
<<<<<<< HEAD
    virtual sf::Sprite get_Tower_Sprite() = 0;
    Board* GameBoard;
=======
>>>>>>> ee102580a027411ded11e2a2426c7660d091d4ad

public:
    Tower(int,int,int,pos,Board*);

    virtual void locate_sheep(vector<Sheep*>);
    void shoot(Sheep*,Board*);
    pos get_position();
    virtual sf::Sprite get_Tower_Sprite() = 0;




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


inline void mytimer(clock_t sec) //en funktion som fördröjer skotten i sec-antal sekunder
{
    clock_t start_time = clock();
    clock_t end_time = sec*1000 + start_time;
    while(clock() != end_time);
}





#endif // TOWER_H
