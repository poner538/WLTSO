/*
 * FILNAMN:       Shop.cc
 * PROGRAMMERARE: Daniel Brattg�rd 900926-3394, Y3a
 *                Marie Ekbrant 890401-2740, Y3a
 * DATUM:         2013-12-
 *
 * BESKRIVNING
 * Handla saker
 */

//Includes...


Shop::Shop();
~Shop();
sf::Image ShopImage(bildnamn.jpg)
sf::Sprite ShopSprite(ShopImage.jpg)
int price_tower1
int price_tower2

//Medlemsfunktioner
void build_tower1() //�ppnas fr�n int main �r min tnake i nul�get
{
	if(event.mouseButton.button == sf::Mouse::Left)
	{
		towerplacement = [event.mouseButton.x, event.mouseButton.y];
		Board::exist(towerplacement);
		
		//L�gg in i r�tt ordning
	}
    //Kolla om tillr�ckligt med pengar
    //Kolla om ledig plats
}
 //  Board::exist(pos rightupper_corner);
 //  Board::exist(pos leftupper_corner);  //Denna ges av musen
 //  Board::exist(pos rightlower_corner);
 //  Board::exist(pos leftlower_corner);



void build_tower2()
