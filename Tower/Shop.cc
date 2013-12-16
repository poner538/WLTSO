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
    GameBoard = new_board;
    GameController = new_controller;
}
Shop::~Shop()
{

}

sf::Sprite Shop::get_Shop_Sprite()
{
    return Shop_Sprite;
}


//Medlemsfunktioner
void Shop::build_Catapult_Tower() //Öppnas från int main är min tnake i nuläget
{
	if(GameEvent->mouseButton.button == sf::Mouse::Left) //Kollar om vänster musknapp används.
	{
		pos towerplacement;
        towerplacement.x_pos = GameEvent->mouseButton.x;
        towerplacement.y_pos = GameEvent->mouseButton.y;
		if(GameBoard->exist(towerplacement) == true) //Kollar om det är ledigt där tornet skall byggas
        {
            if(GameController->gold_check(-100) == true) //Finns det tillräckligt med pengar?
            {
                Catapult_tower(towerplacement, GameBoard); //Här skall tornet byggas är tanken iaf
            }
            else return;
        }
		else return;
	}

}

void Shop::build_Shooting_Tower() //Öppnas från int main är min tnake i nuläget
{
	if(GameEvent->mouseButton.button == sf::Mouse::Left) //Kollar om vänster musknapp används.
	{
		pos towerplacement;
        towerplacement.x_pos = GameEvent->mouseButton.x;
        towerplacement.y_pos = GameEvent->mouseButton.y;
		if(GameBoard->exist(towerplacement) == true) //Kollar om det är ledigt där tornet skall byggas
        {
            if(GameController->gold_check(-15) == true) //Finns det tillräckligt med pengar?
            {
                Shooting_tower(towerplacement, GameBoard); //Här skall tornet byggas är tanken iaf
            }
            else return;
        }
		else return;
	}

}


