#include "Controller.h"

Controller Controller::controller(100,100);

Controller::Controller(int new_gold, int new_lives)
{
    gold = new_gold;
    current_lives = new_lives;
    points = 0;
}

void Controller::change_gold(const int value)
{
    if ((gold + value) < 0)
    {
        //neeeej, pengar Shop.NotEnoghMoney() någon form av utskrift eller nåt.
    }
    gold = gold + value;
}

void Controller::change_points(const int value)
{
    points = points + value;
}

void Controller::lives()
{
    if (current_lives == 1)
    {
        //Game.GameOver() kanske det kan heta
    }
    current_lives = current_lives - 1;
}
