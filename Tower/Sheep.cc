#include <iostream>
#include <SFML/Graphics.hpp>

#include "Sheep.h"
#include "Controller.h"

Sheep::Sheep(int new_speed, int new_hp, int new_bounty)
{
    speed = new_speed;
    hp = new_hp;
    bounty = new_bounty;

}

void Sheep::hit(int damage)
{
    if (damage > hp)
    {
        Controller::controller.change_gold(bounty);
        Controller::controller.change_points(bounty);//Eller om vi ska ha datamedlem points
        delete this;
    }
    else
    {
        hp = hp - damage;
    }
}

pos Sheep::get_position()
{
    return current_position;
}

void Sheep::set_position(pos new_position)
{
    current_position = new_position;
    return;
}

EasySheep::EasySheep() : Sheep (1/*speed*/, 100/*hp*/, 6/*bounty*/)
{
    if (!Sheep_Texture.loadFromFile(filename))
    {
       std::cout << "Det funka inte! wow omg so förort very latin kings" << std::endl;
    }

    Sheep_Sprite.setTexture(Sheep_Texture);
}

MediumSheep::MediumSheep() : Sheep (2/*speed*/, 200/*hp*/, 12/*bounty*/)
{
    if (!Sheep_Texture.loadFromFile(filename))
    {
        std::cout << "Det funka inte! wow omg so förort very latin kings" << std::endl;
    }

    Sheep_Sprite.setTexture(Sheep_Texture);
}

HardSheep::HardSheep() : Sheep (3/*speed*/, 300/*hp*/, 18/*bounty*/)
{
    if (!Sheep_Texture.loadFromFile(filename))
    {
        std::cout << "Det funka inte! wow omg so förort very latin kings" << std::endl;
    }

    Sheep_Sprite.setTexture(Sheep_Texture);
}
