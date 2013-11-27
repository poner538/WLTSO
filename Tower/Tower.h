#ifndef TOWER_H
#define TOWER_H
#include <SFML/Graphics.hpp>

using namespace std;

/*
    Basklass för torn
*/
class Tower
{
protected:
    int range;
    int shooting_speed;
    int dmg;
    pos current_pos;
   // int current_graphic_state;

public:
    Tower(int,int,int);

//virtual void shoot(int dmg,Sheep sheep_target);
    virtual void locate_sheep(vector<int>,);

};


class Catapult_tower : public Tower
{
    public:
    Catapult_tower();

};

class Shooting_tower : public Tower
{
    public:
    Shooting_tower();
};






#endif // TOWER_H
