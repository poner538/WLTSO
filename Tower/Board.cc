/*
* FILNAMN:          Board.cc
* PROGRAMMERARE:    Johanna Laidla  910712-5826, Y3a
                    Ema Becirovic   920510-6249, Y3a
* DATUM:            2013-mm-dd
*
* BESKRIVNING
*
*
*/

#include "Sheep.h"
#include "Tower.h"
#include "Shot.h"
#include "Course.h"
#include "Board.h"

Board::Board(Course new_Board_Course)
{
    Board_Course = new_Board_Course;
}

vector<Shot> Board::get_Shot()
{
    return Shot_list;
}

void Board::set_Shot(Shot new_Shot)
{
    Shot_list.push_back(new_Shot);
}

Course Board::get_Course()
{
    return Board_Course;
}

vector<Tower> Board::get_Tower()
{
    return Tower_list;
}

void Board::set_Tower(Tower new_Tower)
{
    Tower_list.push_back(new_Tower);
}

vector<Sheep> Board::get_Sheep()
{
    return Sheep_list;
}

void Board::set_Sheep(Sheep& new_Sheep)
{
    Sheep_list.push_back(new_Sheep);
}

bool Board::exist(pos other_pos)
{
    bool t = false;
    for (unsigned int i = 0; i < Sheep_list.size(); i++)
    {
        ;
        if ((Sheep_list.at(i).get_position().x_pos == other_pos.x_pos) and  (Sheep_list.at(i).get_position().y_pos == other_pos.y_pos))
        {
            return true;
        }
    }

    for (unsigned int i = 0; i < Tower_list.size(); i++)
    {
        if ((Tower_list.at(i)).get_position() == other_pos)
        {
            return true;
        }
    }

    t = reserved_space(other_pos.x_pos, other_pos.y_pos);

    return t;
}

bool Board::reserved_space(int x, int y)
{
    bool t = false;
    if ((Board_Course.r0).contains(x, y))
    {
        t = true;
    }
    else if ((Board_Course.r1).contains(x, y))
    {
        t = true;
    }
    else if ((Board_Course.r2).contains(x, y))
    {
        t = true;
    }
    else if ((Board_Course.r3).contains(x, y))
    {
        t = true;
    }
    else if ((Board_Course.r4).contains(x, y))
    {
        t = true;
    }
    else if ((Board_Course.r5).contains(x, y))
    {
        t = true;
    }
    return t;
}

distance = distance + time*