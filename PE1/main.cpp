/**
 * William Dellinger
 * PE 1
 * This program tests the Point class by creating several points,
 * moving them, and calculating the distance between them
*/
#include <iostream>
#include "Point.h"

int main(){
    //create points
    Point p1;
    Point p2(1,2);
    Point p3(3,5);

    //print coordinates
    std::cout << "p1: (" << p1.get_x() << "," << p1.get_y() << ")" << std::endl;
    std::cout << "p2: (" << p2.get_x() << "," << p2.get_y() << ")" << std::endl;
    std::cout << "p3: (" << p3.get_x() << "," << p3.get_y() << ")" << std::endl;

    //print distances between points
    std::cout << "The distance between p1 and p2 is: " << p1.distance(p2) << std::endl;
    std::cout << "The distance between p1 and p3 is: " << p1.distance(p3) << std::endl;
    std::cout << "The distance between p2 and p3 is: " << p2.distance(p3) << std::endl;

    //move point p1 by a positive value and print updated coordinates and distances
    p1.translate(7);
    std::cout << "p1: (" << p1.get_x() << "," << p1.get_y() << ")" << std::endl;
    std::cout << "The distance between p1 and p2 is: " << p1.distance(p2) << std::endl;
    std::cout << "The distance between p1 and p3 is: " << p1.distance(p3) << std::endl;

    //move point p1 by a negative value and print updated coordinates and distances
    p1.translate(-9);
    std::cout << "p1: (" << p1.get_x() << "," << p1.get_y() << ")" << std::endl;
    std::cout << "The distance between p1 and p2 is: " << p1.distance(p2) << std::endl;
    std::cout << "The distance between p1 and p3 is: " << p1.distance(p3) << std::endl;
}