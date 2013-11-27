#include <string>
#include <SFML/Graphics.hpp>

class TextureHandler
{
public:
    TextureHandler();
    sf::Texture getEasySheep();
    sf::Texture getMediumSheep();
    sf::Texture getHardSheep();

    static TextureHandler texturehandler;


private:
    std::string filenameEasySheep = "EasySheep.jpg";
    std::string filenameMediumSheep = "MediumSheep.jpg";
    std::string filenameHardSheep = "HardSheep.jpg";

    sf::Texture EasySheep_Texture;
    sf::Texture MediumSheep_Texture;
    sf::Texture HardSheep_Texture;
};
