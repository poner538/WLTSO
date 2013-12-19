/*
* FILNAMN:          Controller.h
* PROGRAMMERARE:    Johanna Laidla      910712-5826, Y3a
                    Ema Becirovic       920510-6249, Y3a
                    Karin Lockowandt    910213-3260, Yi3
                    Daniel Brattgård    900926-3394, Y3a
                    Pontus Erlesand     910117-1172, Y3a
                    Marie Ekbrant       890401-2740, Y3a
* DATUM:            2013-12-19
*
* Headerfil till klassen Controller.
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
    int get_points();
    int get_gold();
    bool get_made_shot();
    void change_made_shot(bool);

    static Controller controller;

private:
    int gold = 0;
    int points = 0;
    int current_lives = 0;
    bool made_shot = false;

};

#endif // CONTROLLER_H
