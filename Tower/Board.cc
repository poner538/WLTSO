/*
* FILNAMN:          Board.cc
* PROGRAMMERARE:    Johanna Laidla  910712-5826, Y3a
*                   Ema Becirovic   920510-6249, Y3a
* DATUM:            2013-12-18
*
* Board är själva spelbrädet och har koll på alla objekt som befinner sig på brädet.
*
*
*/

#include "Board.h"
#include <vector>

//Konstruktor

Board::Board(Course& new_Board_Course)
{
    Board_Course = new_Board_Course;
    Board_Sprite.setTexture(TextureHandler::texturehandler.getBoard());

}

//Hämtar alla Shots på banan
vector<Shot*>& Board::get_Shot()
{
    return Shot_list;
}

//Lägger till nya Shots i listan
void Board::set_Shot(Shot* new_Shot)
{
    Shot_list.push_back(new_Shot);
}

//Hämtar Course som finns på banan
Course Board::get_Course()
{
    return Board_Course;
}

//Hämtar alla Towers på banan
vector<Tower*>& Board::get_Tower()
{
    return Tower_list;
}

//Lägger till nya Towers i listan
void Board::set_Tower(Tower* new_Tower)
{
    Tower_list.push_back(new_Tower);
}

//Hämtar alla Sheep på banan
vector<Sheep*>& Board::get_Sheep()
{
    return Sheep_list;
}

//Lägger till nya Sheep i listan
void Board::set_Sheep(Sheep* new_Sheep)
{
    Sheep_list.push_back(new_Sheep);
}

//Returnerar Boardens Sprite
sf::Sprite Board::get_Board_Sprite()
{
    return Board_Sprite;
}

//Kontrollerar ifall det är möjligt att placera ut torn på banan
bool Board::exist(pos other_pos)
{
    bool t = false;

    for (unsigned int i = 0; i < Tower_list.size(); i++)
    {
        if (Tower_list.at(i)->get_Tower_Sprite().getGlobalBounds().contains(other_pos.x_pos, other_pos.y_pos))
        {
            return true;
        }
    }

    if(other_pos.x_pos >= 600)
        return true;

    t = reserved_space(other_pos.x_pos, other_pos.y_pos);

    return t;
}

//Kontrollerar ifall rutorna på brädet är upptagna
bool Board::reserved_space(int x, int y)
{
    bool t = false;
    if ((Board_Course.get_Rect(0)).contains(x, y))
    {
        t = true;
    }
    else if ((Board_Course.get_Rect(1)).contains(x, y))
    {
        t = true;
    }
    else if ((Board_Course.get_Rect(2)).contains(x, y))
    {
        t = true;
    }
    else if ((Board_Course.get_Rect(3)).contains(x, y))
    {
        t = true;
    }
    else if ((Board_Course.get_Rect(4)).contains(x, y))
    {
        t = true;
    }
    else if ((Board_Course.get_Rect(5)).contains(x, y))
    {
        t = true;
    }
    return t;
}


