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
//    sf::Image ShopImage(bildnamn.jpg);
 //   sf::Sprite ShopSprite(ShopImage.jpg);




    //Medlemsfunktioner
    void build_Catapult_Tower();
    void build_Shooting_Tower();

    //Knappar till tornbyggen
    int button_width = 80; //ex bredd
    int button_height = 200; //ex höjd
    sf::Rect<int> Catapult_tower_button{sf::Rect<int>(610,300, button_width, button_height)};
    sf::Rect<int> Shooting_tower_button{sf::Rect<int>(710,300, button_width, button_height)};


/*Ska till Main:
Kollar om det är vänster musknapp som använts och vilket torn som i så fall ska byggas
if(event.mouseButton.button == sf::Mouse::Left)
{
    if(((Shop.Catapult_Tower_button).contains(event.mouseButton.x, event.mouseButton.y)))
        {
            Shop::build_Catapult_Tower();
        }


    else if(((Shop.Shooting_Tower_button).contains(event.mouseButton.x, event.mouseButton.y)))
        {
            Shop::build_Shooting_Tower();
        }
    else
        //Någon form av avhopp, dvs inte bygga torn.
}
*/




protected:



    Board* gameboard;
    Controller* gamecontroller;
    sf::Event* gameevent;




};
#endif
