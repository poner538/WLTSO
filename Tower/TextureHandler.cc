/*
* FILNAMN:          TextueHandler.cc
* PROGRAMMERARE:    Johanna Laidla  910712-5826, Y3a
                    Ema Becirovic   920510-6249, Y3a
* DATUM:            2013-mm-dd
*
* BESKRIVNING
*
*
*/

#include <iostream>
#include "TextureHandler.h"

TextureHandler TextureHandler::texturehandler(1);

TextureHandler::TextureHandler(int dummy)
{
    if (!EasySheep_Texture.loadFromFile(filenameEasySheep))
    {
       std::cout << "EasySheep laddades inte! :(" << std::endl;
    }
     if (!MediumSheep_Texture.loadFromFile(filenameMediumSheep))
    {
       std::cout << "MediumSheep laddades inte! :(" << std::endl;
    }
     if (!HardSheep_Texture.loadFromFile(filenameHardSheep))
    {
       std::cout << "HardSheep laddades inte! :(" << std::endl;
    }
     if (!Catapult_tower_Texture.loadFromFile(filenameCatapult_tower))
    {
       std::cout << "Catapult Tower laddades inte! :(" << std::endl;
    }
     if (!Shooting_tower_Texture.loadFromFile(filenameShooting_tower))
    {
       std::cout << "Shooting Tower laddades inte! :(" << std::endl;
    }
    if (!Shot_Texture.loadFromFile(filenameShot))
    {
        std::cout << "Shot laddades inte! :(" << std::endl;
    }
    if (!Course_Texture.loadFromFile(filenameCourse))
    {
        std::cout << "Course laddedes inte! :(" << std::endl;
    }
}

sf::Texture TextureHandler::getEasySheep()
{
    return EasySheep_Texture;
}

sf::Texture TextureHandler::getMediumSheep()
{
    return MediumSheep_Texture;
}

sf::Texture TextureHandler::getHardSheep()
{
    return HardSheep_Texture;
}

sf::Texture TextureHandler::getCatapult_tower()
{
    return Catapult_tower_Texture;
}

sf::Texture TextureHandler::getShooting_tower()
{
    return Shooting_tower_Texture;
}

sf::Texture TextureHandler::getShot()
{
    return Shot_Texture;
}

sf::Texture TextureHandler::getCourse()
{
    return Course_Texture;
}
