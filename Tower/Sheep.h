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

#include <SFML/Graphics.hpp>
#include <string>

//höhö hittepå
struct pos
{
    int x_pos = 0;
    int y_pos = 0;
    int waypoint_number = 0;
};



class Sheep
{
public:
    /*The big 5*/
    Sheep(int new_speed, int new_hp, int new_bounty);
    virtual ~Sheep() = default;
    Sheep(const Sheep& other) = delete; //Kopieringskonstrukotr
    Sheep(const Sheep&& other) = delete; //Kopieringskonstruktor med move
    Sheep& operator=(const Sheep& other) = delete; //Tilldelningspoerator
    Sheep& operator=(const Sheep&& other) = delete; //Tilldelningspoperator med move

    /*Funktioner*/
    void hit(int damage);

    /*Virtuella funktioner*/
    virtual pos get_position() = 0; //pos inte ännu definierad
    virtual void set_position(pos new_position)= 0;
    virtual sf::Sprite get_Sheep_Sprite() = 0;

protected:
    //Datamedlemmar
    int current_graphic_state;
    int hp = 0;
    int speed = 0;
    int bounty = 0;

};

class EasySheep: public Sheep
{

public:
    EasySheep();
    pos get_position();
    void set_position(pos new_position);
    sf::Sprite get_Sheep_Sprite();

private:

    int current_graphic_state = 1;
    sf::Sprite Sheep_Sprite;
    pos current_position;
    int current_waypoint = 0;
    int next_waypoint = 0;
};

class MediumSheep: public Sheep
{

public:
    MediumSheep();
    pos get_position();
    void set_position(pos new_position);
    sf::Sprite get_Sheep_Sprite();

private:
    int current_graphic_state = 1;
    sf::Sprite Sheep_Sprite;
    pos current_position;
    int current_waypoint = 0;
    int next_waypoint = 0;
};

class HardSheep: public Sheep
{

public:
    HardSheep();
    pos get_position();
    void set_position(pos new_position);
    sf::Sprite get_Sheep_Sprite();

private:
    int current_graphic_state = 1;
    sf::Sprite Sheep_Sprite;
    pos current_position;
    int current_waypoint = 0;
    int next_waypoint = 0;
};



