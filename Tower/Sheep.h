/*
* FILNAMN:          Sheep.h
* PROGRAMMERARE:    Johanna Laidla  910712-5826, Y3a
                    Ema Becirovic   920510-6249, Y3a
* DATUM:            2013-mm-dd
*
* BESKRIVNING
*
*
*/
#ifndef SHEEP_H
#define SHEEP_H
#include <SFML/Graphics.hpp>
#include <string>


//höhö hittepå
struct pos
{
    int x_pos = 0;
    int y_pos = 0;
};



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


    /*Virtuella funktioner*/
    virtual pos get_position() = 0; //pos inte ännu definierad
    virtual void set_position(pos new_position)= 0;
    virtual sf::Sprite get_Sheep_Sprite() = 0;
    virtual void update_position(float time) = 0;

protected:
    //Datamedlemmar
    int current_graphic_state;
    int hp = 0;
    int speed = 0;
    int bounty = 0;
    float distance = 0;
    Course current_Course;

};

class EasySheep: public Sheep
{

public:
    EasySheep(Course new_Course);
    pos get_position();
    void set_position(pos new_position);
    sf::Sprite get_Sheep_Sprite();
    void update_position(float time);

private:

    int current_graphic_state = 1;
    sf::Sprite Sheep_Sprite;
    pos current_position{-5, 10};
    pos next_position{20, 10};
    int next_waypoint = 1;

};

class MediumSheep: public Sheep
{

public:
    MediumSheep(Course new_Course);
    pos get_position();
    void set_position(pos new_position);
    sf::Sprite get_Sheep_Sprite();

private:
    int current_graphic_state = 1;
    sf::Sprite Sheep_Sprite;
    pos current_position{-5, 10};
    pos next_position{20, 10};
    int next_waypoint = 1;
};

class HardSheep: public Sheep
{

public:
    HardSheep(Course new_Course);
    pos get_position();
    void set_position(pos new_position);
    sf::Sprite get_Sheep_Sprite();

private:
    int current_graphic_state = 1;
    sf::Sprite Sheep_Sprite;
    pos current_position{-5, 10};
    pos next_position{20, 10};
    int next_waypoint = 1;
};

#endif // SHEEP_H
