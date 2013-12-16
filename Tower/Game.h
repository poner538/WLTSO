/*
* FILNAMN:          Game.h
* PROGRAMMERARE:    Johanna Laidla  910712-5826, Y3a
                    Ema Becirovic   920510-6249, Y3a
* DATUM:            2013-mm-dd
*
* BESKRIVNING
*
*
*/
#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "Course.h"
#include "Board.h"
#include "Shop.h"

class Game
{
public:
    /*The big 5*/
    Game(sf::RenderWindow*, Board*);
    ~Game() = default;
    Game(const Game& other) = delete; //Kopieringskonstruktor
    Game(const Game&& other) = delete; //Kopieringskonstruktor med move
    Game& operator=(const Game& other) = delete; //Tilldelningspoerator
    Game& operator=(const Game&& other) = delete; //Tilldelningspoperator med move


    /*Medlemsfunktioner*/
    void feed_Sheep(vector<int> current_wave);
    void game_on(); //Uppdatera grafik, skapa board
    void game_over();
    void update_background_graphics();
    void update_foreground_graphics();

private:
    /*Datamedlemmar*/
    sf::RenderWindow* GameWindow;
    Board* GameBoard;
    Shop* GameShop;
    int feeding_time = 10;

    pos course_start_pos{-5,20};
    vector<vector<int>> wave;
    bool start_stop = true;
    int current_level = 1;
    int current_sheep = 1;
    bool can_I_shop = true;

};

#endif // GAME_H
