/*
* FILNAMN:          Tower.h
* PROGRAMMERARE:    Johanna Laidla      910712-5826, Y3a
                    Ema Becirovic       920510-6249, Y3a
                    Karin Lockowandt    910213-3260, Yi3
                    Daniel Brattgård    900926-3394, Y3a
                    Pontus Erlesand     910117-1172, Y3a
                    Marie Ekbrant       890401-2740, Y3a
* DATUM:            2013-12-19
*
* Headerfil till klassen Tower
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
public:
    Tower(int,float,int,pos,Board*);
    ~Tower();
    Tower(const Tower& other) = delete; //Kopieringskonstruktor
    Tower(const Tower&& other) = delete; //Kopieringskonstruktor med move
    Tower& operator=(const Tower& other) = delete; //Tilldelningsoperator
    Tower& operator=(const Tower&& other) = delete; //Tilldelningspoperator med move

    virtual void locate_sheep(vector<Sheep*>&,float);
    void shoot(Sheep*&);
    pos get_position();
    virtual sf::Sprite get_Tower_Sprite() = 0;

protected:
    int range;
    float shooting_speed; // i sekunder
    int dmg;
    pos T_pos;
    Board* GameBoard;
    bool shot_timer(float);
    float temptime = 0;
};


class Catapult_tower : public Tower
{
public:
    Catapult_tower(pos,Board*);
    sf::Sprite get_Tower_Sprite();

private:
    sf::Sprite Tower_Sprite;
    int current_graphic_state = 1;
    sf::IntRect TowerRect;

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
