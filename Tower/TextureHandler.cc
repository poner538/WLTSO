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
    if (!BossSheep_Texture.loadFromFile(filenameBossSheep))
    {
        std::cout << "BossSheep laddades inte! :(" << std::endl;
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
        std::cout << "Course laddades inte! :(" << std::endl;
    }
    if (!Board_Texture.loadFromFile(filenameBoard))
    {
        std::cout << "Board laddades inte! :(" << std::endl;
    }
}

sf::Texture& TextureHandler::getEasySheep()
{
    if (!EasySheep_Texture.loadFromFile(filenameEasySheep))
    {
        std::cout << "EasySheep laddades inte! :(" << std::endl;
    }
    return EasySheep_Texture;
}

sf::Texture& TextureHandler::getMediumSheep()
{
    if (!MediumSheep_Texture.loadFromFile(filenameMediumSheep))
    {
        std::cout << "MediumSheep laddades inte! :(" << std::endl;
    }
    return MediumSheep_Texture;
}

sf::Texture& TextureHandler::getHardSheep()
{
    if (!HardSheep_Texture.loadFromFile(filenameHardSheep))
    {
        std::cout << "HardSheep laddades inte! :(" << std::endl;
    }
    return HardSheep_Texture;
}

sf::Texture& TextureHandler::getBossSheep()
{
    if (!BossSheep_Texture.loadFromFile(filenameBossSheep))
    {
        std::cout << "BossSheep laddades inte! :(" << std::endl;
    }
    return BossSheep_Texture;
}

sf::Texture& TextureHandler::getCatapult_tower()
{
    if (!Catapult_tower_Texture.loadFromFile(filenameCatapult_tower))
    {
        std::cout << "Catapult Tower laddades inte! :(" << std::endl;
    }
    return Catapult_tower_Texture;
}

sf::Texture& TextureHandler::getShooting_tower()
{
    if (!Shooting_tower_Texture.loadFromFile(filenameShooting_tower))
    {
        std::cout << "Shooting Tower laddades inte! :(" << std::endl;
    }
    return Shooting_tower_Texture;
}

sf::Texture& TextureHandler::getShot()
{
    if (!Shot_Texture.loadFromFile(filenameShot))
    {
        std::cout << "Shot laddades inte! :(" << std::endl;
    }
    return Shot_Texture;
}

sf::Texture& TextureHandler::getCourse()
{
    if (!Course_Texture.loadFromFile(filenameCourse))
    {
        std::cout << "Course laddades inte! :(" << std::endl;
    }
    return Course_Texture;
}

sf::Texture& TextureHandler::getBoard()
{
    if (!Board_Texture.loadFromFile(filenameBoard))
    {
        std::cout << "Board laddades inte! :(" << std::endl;
    }
    return Board_Texture;
}
