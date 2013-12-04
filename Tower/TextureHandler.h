/*
* FILNAMN:          TExtureHandler.h
* PROGRAMMERARE:    Johanna Laidla  910712-5826, Y3a
                    Ema Becirovic   920510-6249, Y3a
* DATUM:            2013-mm-dd
*
* BESKRIVNING
*
*
*/

#include <string>
#include <SFML/Graphics.hpp>

class TextureHandler
{
public:
    TextureHandler();
    sf::Texture getEasySheep();
    sf::Texture getMediumSheep();
    sf::Texture getHardSheep();
    sf::Texture getTower1();
    sf::Texture getTower2();
    sf::Texture getShot();

    static TextureHandler texturehandler;


private:
    std::string filenameEasySheep = "EasySheep.jpg";
    std::string filenameMediumSheep = "MediumSheep.jpg";
    std::string filenameHardSheep = "HardSheep.jpg";
    std::string filenameTower1;
    std::string filenameTower2;
    std::string filenameShot;

    sf::Texture EasySheep_Texture;
    sf::Texture MediumSheep_Texture;
    sf::Texture HardSheep_Texture;
    sf::Texture Tower1_Texture;
    sf::Texture Tower2_Texture;
    sf::Texture Shot_Texture;
};
