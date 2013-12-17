/*
* FILNAMN:          Controller.h
* PROGRAMMERARE:    Johanna Laidla  910712-5826, Y3a
                    Ema Becirovic   920510-6249, Y3a
* DATUM:            2013-mm-dd
*
* BESKRIVNING
*
*
*/

#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller
{
public:
    /*The big 5*/
    Controller(int new_gold, int new_lives);
    ~Controller() = default;
    Controller(const Controller& other) = delete; //Kopieringskonstruktor
    Controller(const Controller&& other) = delete; //Kopieringskonstruktor med move
    Controller& operator=(const Controller& other) = delete; //Tilldelningspoerator
    Controller& operator=(const Controller&& other) = delete; //Tilldelningspoperator med move

    bool gold_check(const int value);
    void change_gold(const int value);
    void change_points(const int value);
    void lives();
    int get_lives();

    static Controller controller;

private:
    int gold = 0;
    int points = 0;
    int current_lives = 100;
};

#endif // CONTROLLER_H
