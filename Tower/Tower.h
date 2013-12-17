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
#include "Shot.h"
using namespace std;
class Board;
class Sheep;
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
    Board* GameBoard;
    bool shot_timer(float);
    float temptime = 0;

public:
    Tower(int,int,int,pos,Board*);

    virtual void locate_sheep(vector<Sheep*>&,float);
    void shoot(Sheep*&);
    pos get_position();
    virtual sf::Sprite get_Tower_Sprite() = 0;




};


class Catapult_tower : public Tower
{
public:
    Catapult_tower(pos,Board*);
    sf::Sprite get_Tower_Sprite();

private:
    sf::Sprite Tower_Sprite;
    int current_graphic_state = 1;

};

class Shooting_tower : public Tower
{
public:
    Shooting_tower(pos,Board*);
    sf::Sprite get_Tower_Sprite();

private:
    sf::Sprite Tower_Sprite;
    int current_graphic_state = 1;
};








#endif // TOWER_H
