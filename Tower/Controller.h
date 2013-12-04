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

class Controller
{
public:
    Controller(int new_gold, int new_lives);

    void change_gold(const int value);
    void change_points(const int value);
    void lives();

    static Controller controller;

private:
    int gold = 0;
    int points = 0;
    int current_lives = 100;
};
