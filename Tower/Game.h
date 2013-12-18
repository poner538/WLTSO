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
    void game_over(std::string);
    void update_Game(float);
    void update_background_graphics();
    void update_foreground_graphics();
    bool shall_feed = false;
    bool is_running();
    void change_run(bool);
    bool is_shopping();
    void new_wave();
    void change_shopping(bool);
    int get_level();

    bool ending = false;

    bool is_sound1();
    void set_sound1(bool);
    bool is_sound2();
    void set_sound2(bool);

private:
    /*Datamedlemmar*/
    sf::RenderWindow* GameWindow;
    Board* GameBoard;
    Shop* GameShop;
    int feeding_time = 1;
    int current_sheep = 0;
    std::vector<int> current_wave;
    pos course_start_pos {-5,20};

    //Lite olika v�gor
    std::vector<std::vector<int>>
    wave = {
        {1},
        {1,1,1},
        {1,1,1,1,2},
        {2,1,1,2,1,1,2},
        {2,2,1,2,2,1,2,2},
        {1,2,2,2,1,2,2,2,1},
        {1,2,2,2,2,1,2,2,2,2,3},
        {1,2,1,2,3,1,2,1,2,3,1,2,1,2,3},
        {2,2,3,1,3,2,2,2,1,3,2,2,3,1,3},
        {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3}
        };
    bool start_stop = true;
    int current_level = 0;
    bool can_I_shop = true;
    bool sound1 = false;
    bool sound2 = false;

};

#endif // GAME_H
