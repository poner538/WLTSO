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
};
