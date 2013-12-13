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
#ifndef TEXTUREHANDLER_H
#define TEXTUREHANDLER_H
#include <string>
#include <SFML/Graphics.hpp>

class TextureHandler
{
public:
    /*The big 5*/
    TextureHandler(int);
    ~TextureHandler() = default;
    TextureHandler(const TextureHandler& other) = delete; //Kopieringskonstruktor
    TextureHandler(const TextureHandler&& other) = delete; //Kopieringskonstruktor med move
    TextureHandler& operator=(const TextureHandler& other) = delete; //Tilldelningspoerator
    TextureHandler& operator=(const TextureHandler&& other) = delete; //Tilldelningspoperator med move

    sf::Texture getEasySheep();
    sf::Texture getMediumSheep();
    sf::Texture getHardSheep();
    sf::Texture getTower1();
    sf::Texture getTower2();
    sf::Texture getShot();
    sf::Texture getCourse();

    static TextureHandler texturehandler;


private:
    std::string filenameEasySheep = "EasySheep.jpg";
    std::string filenameMediumSheep = "MediumSheep.jpg";
    std::string filenameHardSheep = "HardSheep.jpg";
    std::string filenameTower1;
    std::string filenameTower2;
    std::string filenameShot;
    std::string filenameCourse;

    sf::Texture EasySheep_Texture;
    sf::Texture MediumSheep_Texture;
    sf::Texture HardSheep_Texture;
    sf::Texture Tower1_Texture;
    sf::Texture Tower2_Texture;
    sf::Texture Shot_Texture;
    sf::Texture Course_Texture;
};

#endif // TEXTUREHANDLER_H
