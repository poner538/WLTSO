#include <SFML/Graphics.hpp>

using namespace std;

/*

Basklass för torn
*/
class Tower
{
    virtual Tower(int new_range,int new_shooting_speed,int new_dmg) = 0;

};
