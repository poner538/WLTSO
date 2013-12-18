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
    TextureHandler& operator=(const TextureHandler& other) = delete; //Tilldelningsoperator
    TextureHandler& operator=(const TextureHandler&& other) = delete; //Tilldelningspoperator med move

    sf::Texture& getEasySheep();
    sf::Texture& getMediumSheep();
    sf::Texture& getHardSheep();
    sf::Texture& getCatapult_tower();
    sf::Texture& getShooting_tower();
    sf::Texture& getShot();
    sf::Texture& getCourse();
    sf::Texture& getBoard();

    static TextureHandler texturehandler;


private:
    std::string filenameEasySheep = "EasySheep.png";
    std::string filenameMediumSheep = "MediumSheep.jpg";
    std::string filenameHardSheep = "HardSheep.jpg";
    std::string filenameCatapult_tower = "CatapultTower.jpg";
    std::string filenameShooting_tower = "ShootingTower.jpg";
    std::string filenameShot = "Shot.jpg";
    std::string filenameCourse = "Course.jpg";
    std::string filenameBoard = "Board_shop.jpg";

    sf::Texture EasySheep_Texture;
    sf::Texture MediumSheep_Texture;
    sf::Texture HardSheep_Texture;
    sf::Texture Catapult_tower_Texture;
    sf::Texture Shooting_tower_Texture;
    sf::Texture Shot_Texture;
    sf::Texture Course_Texture;
    sf::Texture Board_Texture;
};

#endif // TEXTUREHANDLER_H
