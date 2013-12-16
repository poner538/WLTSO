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
#include <vector>
#include "Shop.h"
class Board;
class Sheep;

class Game
{
public:
    /*The big 5*/
    Game(sf::RenderWindow*&, Board*&);
    ~Game() = default;
    Game(const Game& other) = delete; //Kopieringskonstruktor
    Game(const Game&& other) = delete; //Kopieringskonstruktor med move
    Game& operator=(const Game& other) = delete; //Tilldelningspoerator
    Game& operator=(const Game&& other) = delete; //Tilldelningspoperator med move


    /*Medlemsfunktioner*/
    void feed_Sheep(float);
    void game_on(); //Uppdatera grafik, skapa board, konstruktor?
    //void game_over();
    void update_Game(float);
    void update_background_graphics();
    void update_foreground_graphics();

    bool game_over = false;
    bool start_stop = true;

private:
    /*Datamedlemmar*/
    sf::RenderWindow* GameWindow;
    Board* GameBoard;
    Shop* GameShop;
    float feeding_time = 1;
    int current_sheep = 0;
    std::vector<int> current_wave;
    bool new_wave = false;

    pos course_start_pos{-5,20};
    std::vector<std::vector<int>> wave = {{1, 1, 1} , {2, 2, 2}};
    int current_level = 0;
    bool can_I_shop = true;

};

#endif // GAME_H
