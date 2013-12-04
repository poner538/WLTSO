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

TextureHandler TextureHandler::texturehandler = TextureHandler();

TextureHandler::TextureHandler()
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
     if (!Tower1_Texture.loadFromFile(filenameTower1))
    {
       std::cout << "Tower1 laddades inte! :(" << std::endl;
    }
     if (!Tower2_Texture.loadFromFile(filenameTower2))
    {
       std::cout << "Tower2 laddades inte! :(" << std::endl;
    }
    if (!Shot_Texture.loadFromFile(filenameShot))
    {
        std::cout << "Shot laddades inte! :(" << std::endl;
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

sf::Texture TextureHandler::getTower1()
{
    return Tower1_Texture;
}

sf::Texture TextureHandler::getTower2()
{
    return Tower2_Texture;
}

sf::Texture TextureHandler::getShot()
{
    return Shot_Texture;
}
