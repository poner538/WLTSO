#include "Tower.h"
#include <iostream>
using namespace std;
int main()
{
    pos posi;
    posi.x_pos = 100;
    posi.y_pos = 25;


    Catapult_tower torn(posi);
    Shooting_tower torn2(posi);
    torn2.locate_sheep();
   // torn.shoot();
    //cout << torn.dmg << "\n";
    return 0;
}
