/*
 * FILNAMN:       Course.cc
 * PROGRAMMERARE: Daniel Brattgård 900926-3394, Y3a
 *                Marie Ekbrant 890401-2740, Y3a
 * DATUM:         2013-12-09
 *
 * BESKRIVNING
 *
 * Hur fåren ska flytta sig under spelet
 */

#include "Course.h"
#include <vector>

Course::Course()
{
    initiate_rectangles();
    Rect0_Sprite.setTexture(TextureHandler::texturehandler.getCourse());
    Rect1_Sprite.setTexture(TextureHandler::texturehandler.getCourse());
    Rect2_Sprite.setTexture(TextureHandler::texturehandler.getCourse());
    Rect3_Sprite.setTexture(TextureHandler::texturehandler.getCourse());
    Rect4_Sprite.setTexture(TextureHandler::texturehandler.getCourse());
    Rect5_Sprite.setTexture(TextureHandler::texturehandler.getCourse());
    Rect0_Sprite.setTextureRect(r0);
    Rect1_Sprite.setTextureRect(r1);
    Rect2_Sprite.setTextureRect(r2);
    Rect3_Sprite.setTextureRect(r3);
    Rect4_Sprite.setTextureRect(r4);
    Rect5_Sprite.setTextureRect(r5);//Mycket hårdkodning nu...
}

sf::Sprite Course::get_Course_Sprite(int number)
{
    if (number == 0)
    {
        return Rect0_Sprite;
    }
    else if (number == 1)
    {
        return Rect1_Sprite;
    }
    else if (number == 2)
    {
        return Rect2_Sprite;
    }
    else if (number == 3)
    {
        return Rect3_Sprite;
    }
    else if (number == 4)
    {
        return Rect4_Sprite;
    }
    else if (number == 5)
    {
        return Rect5_Sprite;
    }
    else
    {
        //vi borde ha en felklass
    }
}

void Course::initiate_rectangles()
{
    int spread = 10; //Tex
    sf::Rect<int> r0{sf::Rect<int>(wp0.x_pos - spread,wp0.y_pos - spread, wp1.x_pos - wp0.x_pos + 2*spread, 2*spread)}; //Hårdkodat med riktningar och sånt +- ema
    sf::Rect<int> r1{sf::Rect<int>(wp1.x_pos - spread,wp1.y_pos - spread, 2*spread, wp2.y_pos - wp1.y_pos + 2*spread)};
    sf::Rect<int> r2{sf::Rect<int>(wp2.x_pos - spread,wp2.y_pos - spread, wp3.x_pos - wp2.x_pos + 2*spread, 2*spread)};
    sf::Rect<int> r3{sf::Rect<int>(wp3.x_pos - spread,wp3.y_pos - spread, 2*spread, wp3.y_pos - wp4.y_pos + 2*spread)};
    sf::Rect<int> r4{sf::Rect<int>(wp4.x_pos - spread,wp4.y_pos - spread, wp5.x_pos - wp4.x_pos + 2*spread, 2*spread)};
    sf::Rect<int> r5{sf::Rect<int>(wp5.x_pos - spread,wp5.y_pos - spread, 2*spread, wp6.y_pos - wp5.y_pos + 2*spread)};

/* (left, top, width, height) struct pos{
    int x_pos;
    int y_pos;
};
 * (wp(i).x_pos - 1)
 * (wp(i).y_pos - 1)
 * (wp(i+1).x_pos - wp(i).x_pos +2)
 * (wp(i+1).y_pos - wp(i).y_pos +2)
 * Enklast att lägga in punkterna var och en för sig med manuell matematik!!!!!
 */
}

/*void waypoint_direction(int Sheep::heading_to)
{
     if (Sheep::heading_to == 1 | 3 | 5)//OR är tanken
     {
        dx = Sheep::speed  //x=x+1 om positionsuppdatering
        dy = 0
     }
     else if (Sheep::heading_to == 2 | 6)
     {
        dx = 0
        dy = Sheep::speed
     }
     else if (Sheep::heading_to == 4)
     {
        dx = 0
        dy = -(Sheep::speed)
     }
}*/

pos Course::get_waypoint(int number)
{
    if (number == 0)
    {
        return wp0;
    }
    else if (number == 1)
    {
        return wp1;
    }
    else if (number == 2)
    {
        return wp2;
    }
    else if (number == 3)
    {
        return wp3;
    }
    else if (number == 4)
    {
        return wp4;
    }
    else if (number == 5)
    {
        return wp5;
    }
    else
    {
        //vi borde ha en felklass
    }
}
