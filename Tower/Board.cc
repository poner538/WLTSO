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

#include "Board.h"
#include <vector>



Board::Board(Course& new_Board_Course)
{
    Board_Course = new_Board_Course;
    Board_Sprite.setTexture(TextureHandler::texturehandler.getBoard());

}

vector<Shot*>& Board::get_Shot()
{
    return Shot_list;
}

void Board::set_Shot(Shot* new_Shot)
{
    Shot_list.push_back(new_Shot);
}

Course Board::get_Course()
{
    return Board_Course;
}

vector<Tower*>& Board::get_Tower()
{
    return Tower_list;
}

void Board::set_Tower(Tower* new_Tower)
{
    Tower_list.push_back(new_Tower);
}

vector<Sheep*>& Board::get_Sheep()
{
    return Sheep_list;
}

void Board::set_Sheep(Sheep* new_Sheep)
{
    Sheep_list.push_back(new_Sheep);
}

sf::Sprite Board::get_Board_Sprite()
{
    return Board_Sprite;
}

bool Board::exist(pos other_pos)
{
    bool t = false;
    for (unsigned int i = 0; i < Tower_list.size(); i++)
    {
        if (Tower_list.at(i)->get_Tower_Sprite().getTextureRect().contains(other_pos.x_pos, other_pos.y_pos))
        {
            return true;
        }
    }

    if(other_pos.x_pos >= 550)
        return true;

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


