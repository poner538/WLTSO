#ifndef TOWER_H
#define TOWER_H
#include <SFML/Graphics.hpp>
#include <ctime>
using namespace std;

/*
    Basklass för torn
*/
class Tower
{
protected:
    int range;
    int shooting_speed; // i sekunder
    int dmg;
    int posx;
    int posy;
   // int current_graphic_state;

public:
    Tower() = default;
    Tower(int,int,int);
    void locate_sheep();
    //void shoot(Sheep);


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


inline void mytimer(clock_t sec) //en funktion som fördröjer skotten i sec-antal sekunder
{
    clock_t start_time = clock();
    clock_t end_time = sec*1000 + start_time;
    while(clock() != end_time);
}





#endif // TOWER_H
