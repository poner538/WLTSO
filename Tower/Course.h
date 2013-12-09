/*
 * FILNAMN:       Course.h
 * PROGRAMMERARE: Daniel Brattgård 900926-3394, Y3a
 *                Marie Ekbrant 890401-2740, Y3a
 * DATUM:         2013-12-09
 *
 * BESKRIVNING
 *
 * Hur fåren ska flytta sig under spelet
 */

 #include <vector> //Det som behövs
 #include <SFML/Graphics.hpp> //Användning av SFMLs rektangelfkn
 
 
 
 
sf::Rect r0(1,2,3,4);
sf::Rect r1(1,2,3,4);
sf::Rect r2(1,2,3,4);
sf::Rect r3(1,2,3,4);
sf::Rect r4(1,2,3,4);
sf::Rect r5(1,2,3,4);

/* (left, top, width, height)
 * (wp(i).x_pos - 1)
 * (wp(i).y_pos - 1)
 * (wp(i+1).x_pos - wp(i).x_pos +2)
 * (wp(i+1).y_pos - wp(i).y_pos +2)
 * Enklast att lägga in punkterna var och en för sig med manuel matematik!!!!!
 */


 struct waypoint{
    int x_pos;
    int y_pos;
    int unused;
}
wp0{-5, 10, 0}, //-5 är utanför den synliga banan
wp1{20, 10, 0},
wp2{20, 80, 0},
wp3{50, 80, 0},
wp4{50, 60, 0},
wp5{70, 60, 0},
wp6{70, 120, 0} //120 är utanför den synliga banan banan
;


 class Course
 {
 public:
    Course() = default; //Konstruktor(default), bara så länge

    /* Våra waypoints för styrning av får
     * Fördefinerade pos1-posn
     *
     */
    Course(vector <pos> waypoints (pos0, pos1, pos2, pos3, pos4, pos5))


    ~Course(); //Destruktor


    fkntyp_oklar loadbackground();//Bör finnas i main()



    void reserve_space(): //Skall den finnas? Inte kunna sätta tornen på banan.


    void waypoint_direction(int);

    //sf::image Courseimage("... .jpg")
    //sf::Sprite CourseSprite(CourseImage)

     //private
 };
