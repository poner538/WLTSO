/*
* FILNAMN:          Board.h
* PROGRAMMERARE:    Johanna Laidla  910712-5826, Y3a
                    Ema Becirovic   920510-6249, Y3a
* DATUM:            2013-12-18
*
* Board är själva spelbrädet och har koll på alla objekt som befinner sig på brädet.
*
*
*/



#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "TextureHandler.h"
#include "Course.h"
#include "Controller.h"

#include "Sheep.h"
#include "Tower.h"
#include "Shot.h"




class Board
{
public:
    /*The big 5*/
    Board(Course& new_Board_Course);
    ~Board() = default;
    Board(const Board& other) = delete; //Kopieringskonstruktor
    Board(const Board&& other) = delete; //Kopieringskonstruktor med move
    Board& operator=(const Board& other) = delete; //Tilldelningspoerator
    Board& operator=(const Board&& other) = delete; //Tilldelningspoperator med move

    /*Funktioner*/
    vector<Shot*>& get_Shot();
    void set_Shot(Shot*);
    Course get_Course();
    vector<Tower*>& get_Tower();
    void set_Tower(Tower*);
    vector<Sheep*>& get_Sheep();
    void set_Sheep(Sheep*);
    bool exist(pos);
    sf::Sprite get_Board_Sprite();

private:
    /*Privata funktioner*/
    bool reserved_space(int, int); //Upptaget? Kommer agera hj‰lpfkn



    /*Datamedlemmar*/
    sf::Sprite Board_Sprite;
    Course Board_Course;
    vector<Sheep*> Sheep_list;
    vector<Tower*> Tower_list;
    vector<Shot*> Shot_list;


};

#endif //BOARD_H
