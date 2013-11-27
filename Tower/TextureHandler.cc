#include <iostream>
#include "TextureHandler.h"

TextureHandler::TextureHandler()
{
    if (!EasySheep_Texture.loadFromFile(filenameEasySheep))
    {
       std::cout << "Det funka inte! wow omg so förort very latin kings" << std::endl;
    }
     if (!MediumSheep_Texture.loadFromFile(filenameMediumSheep))
    {
       std::cout << "Det funka inte! wow omg so förort very latin kings" << std::endl;
    }
     if (!HardSheep_Texture.loadFromFile(filenameHardSheep))
    {
       std::cout << "Det funka inte! wow omg so förort very latin kings" << std::endl;
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
