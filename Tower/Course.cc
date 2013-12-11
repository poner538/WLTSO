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

//Skriv in konstruktor!!

Course::Course()
{

}

void waypoint_direction(int Sheep::heading_to)
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
}

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
