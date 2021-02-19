/**
 * William Dellinger
 * PE 2
 * This program tests the updated Point class by creating several points,
 * moving them, and calculating the distance between them
*/
#include <iostream>
#include <vector>
#include "Point.h"

int main(){

    std::vector<int> vect1 = {1,2,3};
    std::vector<int> vect2 = {4,5,6};
    //create points
    Point p1(3);
    Point p2(vect1);
    Point p3(vect2);
    Point p4(4); //extra point to test errors

    //print coordinates
    std::cout << "p1: (" << p1.get_coordinate(0) << "," << p1.get_coordinate(1) << "," << p1.get_coordinate(2)  << ")" << std::endl;
    std::cout << "p2: (" << p2.get_coordinate(0) << "," << p2.get_coordinate(1) << "," << p2.get_coordinate(2)  << ")" << std::endl;
    std::cout << "p3: (" << p3.get_coordinate(0) << "," << p3.get_coordinate(1) << "," << p3.get_coordinate(2)  << ")" << std::endl;

    //print distances between points
    std::cout << "The distance between p1 and p2 is: " << p1.distance(p2) << std::endl;
    std::cout << "The distance between p1 and p3 is: " << p1.distance(p3) << std::endl;
    std::cout << "The distance between p2 and p3 is: " << p2.distance(p3) << std::endl;

    //move point p1 by a positive value and print updated coordinates and distances
    p1.translate(8);
    std::cout << "p1: (" << p1.get_coordinate(0) << "," << p1.get_coordinate(1) << "," << p1.get_coordinate(2)  << ")" << std::endl;
    std::cout << "The distance between p1 and p2 is: " << p1.distance(p2) << std::endl;
    std::cout << "The distance between p1 and p3 is: " << p1.distance(p3) << std::endl;

    //move point p1 by a negative value and print updated coordinates and distances
    p1.translate(-9);
    std::cout << "p1: (" << p1.get_coordinate(0) << "," << p1.get_coordinate(1) << "," << p1.get_coordinate(2)  << ")" << std::endl;
    std::cout << "The distance between p1 and p2 is: " << p1.distance(p2) << std::endl;
    std::cout << "The distance between p1 and p3 is: " << p1.distance(p3) << std::endl;

    //Extra tests for dimensional compatibility
    /*
    p4.get_coordinate(4);
    p4.set_coordinate(4,100);
    p4.distance(p3);
    */
}