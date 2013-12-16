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

Shop::Shop();
~Shop();
sf::Image ShopImage(bildnamn.jpg)
sf::Sprite ShopSprite(ShopImage.jpg)
int price_tower1
int price_tower2

//Medlemsfunktioner
void build_Catapult_Tower() //Öppnas från int main är min tnake i nuläget
{
	if(event.mouseButton.button == sf::Mouse::Left) //Kollar om vänster musknapp används.
	{
		towerplacement = [event.mouseButton.x, event.mouseButton.y]; //Skapar struct
		if(Board::exist(towerplacement) == true) //Kollar om det är ledigt där tornet skall byggas
        {
            if(Controller::check_gold(-100) == true) //Finns det tillräckligt med pengar?
            {
                Catapult_tower(towerplacement); //Här skall tornet byggas är tanken iaf
            }
            else return;
        }
		else return;
	}

}

void build_Shooting_Tower()
{
	if(event.mouseButton.button == sf::Mouse::Left) //Kollar om vänster musknapp används.
	{
		towerplacement = [event.mouseButton.x, event.mouseButton.y]; //Skapar struct
		if(Board::exist(towerplacement) == true) //Kollar om det är ledigt där tornet skall byggas
        {
            if(Controller::check_gold(-15) == true) //Finns det tillräckligt med pengar?
            {
                Shooting_tower(towerplacement); //Här skall tornet byggas är tanken iaf
            }
            else return;
        }
		else return;
	}

}


