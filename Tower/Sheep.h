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
    Sheep(int new_speed, int new_hp, int new_bounty);
    ~Sheep() = default;
    Sheep(const Sheep& other) = delete; //Kopieringskonstrukotr
    Sheep(const Sheep&& other) = delete; //Kopieringskonstruktor med move
    Sheep& operator=(const Sheep& other) = delete; //Tilldelningspoerator
    Sheep operator=(const Sheep&& other) = delete; //Tilldelningspoperator med move

    void hit(int damage);
    virtual pos get_position() = 0; //pos inte ännu definierad
    virtual void set_position(pos new_position)= 0;

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

private:

    int current_graphic_state = 1;
    sf::Sprite Sheep_Sprite;
    pos current_position;
};

class MediumSheep: public Sheep
{

public:
    MediumSheep();
    pos get_position();
    void set_position(pos new_position);

private:
    int current_graphic_state = 1;
    sf::Sprite Sheep_Sprite;
    pos current_position;

};

class HardSheep: public Sheep
{

public:
    HardSheep();
    pos get_position();
    void set_position(pos new_position);

private:
    int current_graphic_state = 1;
    sf::Sprite Sheep_Sprite;
    pos current_position;
};



