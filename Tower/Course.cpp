/*
 * FILNAMN:       Course.cpp
 * PROGRAMMERARE: Daniel Brattgård 900926-3394, Y3a
 *                Marie Ekbrant 890401-2740, Y3a
 * DATUM:         2013-mm-dd
 *
 * BESKRIVNING
 *
 * Hur fåren ska flytta sig under spelet
 */


void reserve_space()
{
    for (alla rutor mellan waypoint 0 och 1)
        rutan = byggförbud
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
};

