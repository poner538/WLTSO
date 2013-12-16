/*
 * FILNAMN:       Shop.cc
 * PROGRAMMERARE: Daniel Brattg�rd 900926-3394, Y3a
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
void Shop::build_Catapult_Tower() //�ppnas fr�n int main �r min tnake i nul�get
{
	if(GameEvent->mouseButton.button == sf::Mouse::Left) //Kollar om v�nster musknapp anv�nds.
	{
		pos towerplacement;
        towerplacement.x_pos = GameEvent->mouseButton.x;
        towerplacement.y_pos = GameEvent->mouseButton.y;
		if(GameBoard->exist(towerplacement) == true) //Kollar om det �r ledigt d�r tornet skall byggas
        {
            if(GameController->gold_check(-100) == true) //Finns det tillr�ckligt med pengar?
            {
                Catapult_tower(towerplacement, GameBoard); //H�r skall tornet byggas �r tanken iaf
            }
            else return;
        }
		else return;
	}

}

void Shop::build_Shooting_Tower() //�ppnas fr�n int main �r min tnake i nul�get
{
	if(GameEvent->mouseButton.button == sf::Mouse::Left) //Kollar om v�nster musknapp anv�nds.
	{
		pos towerplacement;
        towerplacement.x_pos = GameEvent->mouseButton.x;
        towerplacement.y_pos = GameEvent->mouseButton.y;
		if(GameBoard->exist(towerplacement) == true) //Kollar om det �r ledigt d�r tornet skall byggas
        {
            if(GameController->gold_check(-15) == true) //Finns det tillr�ckligt med pengar?
            {
                Shooting_tower(towerplacement, GameBoard); //H�r skall tornet byggas �r tanken iaf
            }
            else return;
        }
		else return;
	}

}


