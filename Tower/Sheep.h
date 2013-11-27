#include <SFML/Graphics.hpp>
#include <string>

//höhö hittepå
struct pos
{
    int x_pos = 0;
    int y_pos = 0;
    int course_pos = 0;
};

//höhö detta också


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
    pos get_position(); //pos inte ännu definierad
    void set_position(pos new_position);

protected:
    //Datamedlemmar
    int current_graphic_state;
    int hp = 0;
    int speed = 0;
    int bounty = 0;
    pos current_position;
};

class EasySheep: public Sheep
{

public:
    EasySheep();

private:

    int current_graphic_state = 1;
    std::string filename = "EasySheep.jpg";
    sf::Texture Sheep_Texture;
    sf::Sprite Sheep_Sprite;
};

class MediumSheep: public Sheep
{

public:
    MediumSheep();

private:
    int current_graphic_state = 1;
    std::string filename = "MediumSheep.jpg";
    sf::Texture Sheep_Texture;
    sf::Sprite Sheep_Sprite;

};

class HardSheep: public Sheep
{

public:
    HardSheep();

private:
    int current_graphic_state = 1;
    std::string filename = "HardSheep.jpg";
    sf::Texture Sheep_Texture;
    sf::Sprite Sheep_Sprite;
};



