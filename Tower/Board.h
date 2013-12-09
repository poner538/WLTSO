/*
* FILNAMN:          Board.h
* PROGRAMMERARE:    Johanna Laidla  910712-5826, Y3a
                    Ema Becirovic   920510-6249, Y3a
* DATUM:            2013-mm-dd
*
* BESKRIVNING
*
*
*/

#ifndef BOARD_H
#define BOARD_H
#include <vector>

class Board
{
public:
    /*The big 5*/
    Board(Course new_Board_Course);
    ~Board() = default;
    Board(const Board& other) = delete; //Kopieringskonstruktor
    Board(const Board&& other) = delete; //Kopieringskonstruktor med move
    Board& operator=(const Board& other) = delete; //Tilldelningspoerator
    Board& operator=(const Board&& other) = delete; //Tilldelningspoperator med move

    /*Funktioner*/
    vector<Shot> get_Shot();
    void set_Shot(Shot);
    //vector<pos> get_Course();
    vector<Tower> get_Tower();
    void set_Tower(Tower);
    vector<Sheep> get_Sheep();
    void set_Sheep(Sheep);
    bool exist(pos);
    bool reserved_space(int, int); //Upptaget? Kommer agera hjälpfkn

private:
    /*Datamedlemmar*/
    Course Board_Course;
    vector<Sheep> Sheep_list = 0;
    vector<Tower> Tower_list = 0;
    vector<Shot> Shot_list = 0;

};

#endif //BOARD_H
