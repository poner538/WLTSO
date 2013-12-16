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
    gameboard = new_board;
    gamecontroller = new_controller;
}
Shop::~Shop()
{

}
//sf::Image ShopImage(bildnamn.jpg);
//sf::Sprite ShopSprite(ShopImage.jpg);


//Medlemsfunktioner
void Shop::build_Catapult_Tower() //�ppnas fr�n int main �r min tnake i nul�get
{
	if(gameevent->mouseButton.button == sf::Mouse::Left) //Kollar om v�nster musknapp anv�nds.
	{
		pos towerplacement;
        towerplacement.x_pos = gameevent->mouseButton.x;
        towerplacement.y_pos = gameevent->mouseButton.y;
		if(gameboard->exist(towerplacement) == true) //Kollar om det �r ledigt d�r tornet skall byggas
        {
            if(gamecontroller->gold_check(-100) == true) //Finns det tillr�ckligt med pengar?
            {
                Catapult_tower(towerplacement, gameboard); //H�r skall tornet byggas �r tanken iaf
            }
            else return;
        }
		else return;
	}

}

void Shop::build_Shooting_Tower() //�ppnas fr�n int main �r min tnake i nul�get
{
	if(gameevent->mouseButton.button == sf::Mouse::Left) //Kollar om v�nster musknapp anv�nds.
	{
		pos towerplacement;
        towerplacement.x_pos = gameevent->mouseButton.x;
        towerplacement.y_pos = gameevent->mouseButton.y;
		if(gameboard->exist(towerplacement) == true) //Kollar om det �r ledigt d�r tornet skall byggas
        {
            if(gamecontroller->gold_check(-15) == true) //Finns det tillr�ckligt med pengar?
            {
                Shooting_tower(towerplacement, gameboard); //H�r skall tornet byggas �r tanken iaf
            }
            else return;
        }
		else return;
	}

}


