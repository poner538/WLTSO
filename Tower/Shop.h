/*
 * FILNAMN:       Shop.h
 * PROGRAMMERARE: Daniel Brattgård 900926-3394, Y3a
 *                Marie Ekbrant 890401-2740, Y3a
 * DATUM:         2013-12-
 *
 * BESKRIVNING
 * Handla saker
 */

#ifndef SHOP_H
#define SHOP_H
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

class Board;
class Controller;


class Shop
{
public:
    Shop(Board*, Controller*);
    ~Shop();

    sf::Sprite get_Shop_Sprite();




    //Medlemsfunktioner
    void build_Catapult_Tower();
    void build_Shooting_Tower();

    //Knappar till tornbyggen
    int tower_button_width = 80;
    int tower_button_height = 180;
    sf::Rect<int> Catapult_tower_button{sf::Rect<int>(610,210, tower_button_width, tower_button_height)};
    sf::Rect<int> Shooting_tower_button{sf::Rect<int>(710,210, tower_button_width, tower_button_height)};

    //Knappar till paus och ny våg
    int wave_pause_width = 180;
    int wave_pause_height = 80;
    sf::Rect<int> New_Wave_button{sf::Rect<int>(610,410, wave_pause_width, wave_pause_height)};
    sf::Rect<int> Pause_button{sf::Rect<int>(610,510, wave_pause_width, wave_pause_height)};

/*
Ska till Main:
Kollar om det är vänster musknapp som använts och vilket torn som i så fall ska byggas
if(GameEvent->mouseButton.button == sf::Mouse::Left)
{
    if(((GameShop->Catapult_Tower_button).contains(GameEvent->mouseButton.x, GameEvent->mouseButton.y)))
    {
        GameShop->build_Catapult_Tower();
    }
    else if(((GameShop->Shooting_Tower_button).contains(GameEvent->mouseButton.x, GameEvent->mouseButton.y)))
    {
        GameShop->build_Shooting_Tower();
    }
    else if(((GameShop->New_Wave_button).contains(GameEvent->mouseButton.x, GameEvent->mouseButton.y)))
    {
        //Kommando för ny våg av fiender
    }
    else if(((GameShop->Pause_button).contains(GameEvent->mouseButton.x, GameEvent->mouseButton.y)))
    {
        //Pauskommand
    }
    else
        //typ avbryt
        //Någon form av avhopp, dvs inte bygga torn eller paus eller ny våg dvs ingenting egentligen
        //kanske lämna den tom
}
*/




private:


    sf::Sprite Shop_Sprite;
    Board* GameBoard;
    Controller* GameController;
    sf::Event* GameEvent;




};
#endif
