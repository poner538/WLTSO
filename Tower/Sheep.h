/*
* FILNAMN:          Sheep.h
* PROGRAMMERARE:    Johanna Laidla      910712-5826, Y3a
                    Ema Becirovic       920510-6249, Y3a
                    Karin Lockowandt    910213-3260, Yi3
                    Daniel Brattgård    900926-3394, Y3a
                    Pontus Erlesand     910117-1172, Y3a
                    Marie Ekbrant       890401-2740, Y3a
* DATUM:            2013-12-19
*
* Headerfil till klassen Sheep.
*
*
*/
#ifndef SHEEP_H
#define SHEEP_H
#include <SFML/Graphics.hpp>
#include <string>
#include "Course.h"
#include "Controller.h"




class Sheep
{
public:
    /*The big 5*/
    Sheep(int new_speed, int new_hp, int new_bounty, Course new_Course);
    virtual ~Sheep() = default;
    Sheep(const Sheep& other) = delete; //Kopieringskonstruktor
    Sheep(const Sheep&& other) = delete; //Kopieringskonstruktor med move
    Sheep& operator=(const Sheep& other) = delete; //Tilldelningspoerator
    Sheep& operator=(const Sheep&& other) = delete; //Tilldelningspoperator med move

    /*Funktioner*/
    void hit(int damage);
    float get_distance();
    void change_death(bool);
    bool get_death();



    /*Virtuella funktioner*/
    virtual pos get_position() = 0; //pos inte ännu definierad
    virtual void set_position(pos new_position)= 0;
    virtual sf::Sprite get_Sheep_Sprite() = 0;
    virtual bool update_position(float time) = 0;

protected:
    //Datamedlemmar
    int hp = 0;
    int speed = 0;
    int bounty = 0;
    Course current_Course;
    bool am_I_dead = false;
    float distance = 0;


};

class EasySheep: public Sheep
{

public:
    virtual ~EasySheep() = default;
    EasySheep(Course new_Course);
    pos get_position();
    void set_position(pos new_position);
    sf::Sprite get_Sheep_Sprite();
    bool update_position(float time);

private:

    sf::Sprite Sheep_Sprite;
    pos current_position{-20, 60};
    pos next_position{120, 60};
    int next_waypoint = 1;
};

class MediumSheep: public Sheep
{

public:
    ~MediumSheep() = default;
    MediumSheep(Course new_Course);
    pos get_position();
    void set_position(pos new_position);
    sf::Sprite get_Sheep_Sprite();
    bool update_position(float time);


private:
    sf::Sprite Sheep_Sprite;
    pos current_position{-20, 60};
    pos next_position{120, 60};
    int next_waypoint = 1;
};

class HardSheep: public Sheep
{

public:
    ~HardSheep() = default;
    HardSheep(Course new_Course);
    pos get_position();
    void set_position(pos new_position);
    sf::Sprite get_Sheep_Sprite();
    bool update_position(float time);


private:
    sf::Sprite Sheep_Sprite;
    pos current_position{-20, 60};
    pos next_position{120, 60};
    int next_waypoint = 1;
};

class BossSheep: public Sheep
{

public:
    ~BossSheep() = default;
    BossSheep(Course new_Course);
    pos get_position();
    void set_position(pos new_position);
    sf::Sprite get_Sheep_Sprite();
    bool update_position(float time);


private:
    sf::Sprite Sheep_Sprite;
    pos current_position{-20, 60};
    pos next_position{120, 60};
    int next_waypoint = 1;
};

#endif // SHEEP_H
