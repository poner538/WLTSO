/*
 * FILNAMN:       Shop.cc
 * PROGRAMMERARE: Daniel Brattgård 900926-3394, Y3a
 *                Marie Ekbrant 890401-2740, Y3a
 * DATUM:         2013-12-
 *
 * BESKRIVNING
 * Handla saker
 */

#include "Shop.h"
#include "Board.h"
#include "Controller.h"
#include "Sheep.h"
#include "Tower.h"

Shop::Shop(Board* new_board, Controller* new_controller)
{
    gameboard = new_board;
    gamecontroller = new_controller;
}
Shop::~Shop()
{

}
//sf::Image ShopImage(bildnamn.jpg);
//sf::Sprite ShopSprite(ShopImage.jpg);


//Medlemsfunktioner
void Shop::build_Catapult_Tower() //Öppnas från int main är min tnake i nuläget
{
	if(gameevent->mouseButton.button == sf::Mouse::Left) //Kollar om vänster musknapp används.
	{
		pos towerplacement;
        towerplacement.x_pos = gameevent->mouseButton.x;
        towerplacement.y_pos = gameevent->mouseButton.y;
		if(gameboard->exist(towerplacement) == true) //Kollar om det är ledigt där tornet skall byggas
        {
            if(gamecontroller->gold_check(-100) == true) //Finns det tillräckligt med pengar?
            {
                Catapult_tower(towerplacement, gameboard); //Här skall tornet byggas är tanken iaf
            }
            else return;
        }
		else return;
	}

}

void Shop::build_Shooting_Tower() //Öppnas från int main är min tnake i nuläget
{
	if(gameevent->mouseButton.button == sf::Mouse::Left) //Kollar om vänster musknapp används.
	{
		pos towerplacement;
        towerplacement.x_pos = gameevent->mouseButton.x;
        towerplacement.y_pos = gameevent->mouseButton.y;
		if(gameboard->exist(towerplacement) == true) //Kollar om det är ledigt där tornet skall byggas
        {
            if(gamecontroller->gold_check(-15) == true) //Finns det tillräckligt med pengar?
            {
                Shooting_tower(towerplacement, gameboard); //Här skall tornet byggas är tanken iaf
            }
            else return;
        }
		else return;
	}

}


