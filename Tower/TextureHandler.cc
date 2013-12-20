/*
* FILNAMN:          TextueHandler.cc
* PROGRAMMERARE:    Johanna Laidla  910712-5826, Y3a
                    Ema Becirovic   920510-6249, Y3a
* DATUM:            2013-12-19
*
* BESKRIVNING
*
* Class som hanterar figurer som ska laddas till spelet.
*
*/

#include <iostream>
#include "TextureHandler.h"
//Initierar statisk klass
TextureHandler TextureHandler::texturehandler(1);

//Konstruktor, dummy krävs så att initieringen ska gå bra
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
        std::cout << "Course laddedes inte! :(" << std::endl;
    }
    if (!Board_Texture.loadFromFile(filenameBoard))
    {
        std::cout << "Board laddedes inte! :(" << std::endl;
    }

    //Laddar in texturerna i en vektor så att varje klass kan hämta sin respektive
    //Detta fanns inte med under demon.
    TextureList.push_back(EasySheep_Texture);
    TextureList.push_back(MediumSheep_Texture);
    TextureList.push_back(HardSheep_Texture);
    TextureList.push_back(BossSheep_Texture);
    TextureList.push_back(Catapult_tower_Texture);
    TextureList.push_back(Shooting_tower_Texture);
    TextureList.push_back(Shot_Texture);
    TextureList.push_back(Course_Texture);
    TextureList.push_back(Board_Texture);
}

//Returnerar varje klass specificika Texture
sf::Texture& TextureHandler::getEasySheep()
{
    return TextureList.at(0);
}

sf::Texture& TextureHandler::getMediumSheep()
{
    return TextureList.at(1);
}

sf::Texture& TextureHandler::getHardSheep()
{
    return TextureList.at(2);
}

sf::Texture& TextureHandler::getBossSheep()
{
    return TextureList.at(3);
}

sf::Texture& TextureHandler::getCatapult_tower()
{
    return TextureList.at(4);
}

sf::Texture& TextureHandler::getShooting_tower()
{
    return TextureList.at(5);
}

sf::Texture& TextureHandler::getShot()
{
    return TextureList.at(6);
}

sf::Texture& TextureHandler::getCourse()
{
    return TextureList.at(7);
}

sf::Texture& TextureHandler::getBoard()
{
    return TextureList.at(8);
}
