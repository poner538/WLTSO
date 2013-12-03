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

/*EasySheep*/

EasySheep::EasySheep() : Sheep (1/*speed*/, 100/*hp*/, 6/*bounty*/)
{
    Sheep_Sprite.setTexture(TextureHandler::texturehandler.getEasySheep());
}

pos EasySheep::get_position()
{
    return current_position;
}

void EasySheep::set_position(pos new_position)
{
    current_position = new_position;
    Sheep_Sprite.setPosition(new_position.x_pos, new_position.y_pos);
}

/*MediumSheep*/

MediumSheep::MediumSheep() : Sheep (2/*speed*/, 200/*hp*/, 12/*bounty*/)
{
    Sheep_Sprite.getTexture(TextureHandler::texturehandler.getMediumSheep());
}

pos MediumSheep::get_position()
{
    return current_position;
}

void MediumSheep::set_position(pos new_position)
{
    current_position = new_position;
    Sheep_Sprite.setPosition(new_position.x_pos, new_position.y_pos);
}

/*HardSheep*/

HardSheep::HardSheep() : Sheep (3/*speed*/, 300/*hp*/, 18/*bounty*/)
{
    Sheep_Sprite.setTexture(TextureHandler::texturehandler.getHardSheep());
}

pos HardSheep::get_position()
{
    return current_position;
}

void HardSheep::set_position(pos new_position)
{
    current_position = new_position;
    Sheep_Sprite.setPosition(new_position.x_pos, new_position.y_pos);
}
