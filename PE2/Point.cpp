#include "Point.h"
#include <cmath>
#include <iostream>
#include <assert.h>


/**
 * constructs a point of n dimensions at the origin
 * 
 * @param n number of dimensions for point 
*/
Point::Point(int n) {
    for(int i = 0; i < n; i++){
        p.push_back(0);
    }
}

/**
 * takes in a vector and creates a point with the vectors dimensions
 * 
 * @param vect vector that represents the coordinates of the point
*/
Point::Point(std::vector<int> vect){
    p = vect;
}

/**
 * Returns how many dimensions the point object contains
 * 
 * @return dimensions of point
*/
int Point::get_dimensions(){
    return p.size();
}

/**
 * Returns a particular coordinate in the point object
 * 
 * @param coord coordinate that the user is interested in (e.g. x -> 0, y -> 1, z -> 2,...)
 * @return value at desired coordinate
*/
int Point::get_coordinate(int coord){
    
    if (coord < p.size() && coord >= 0)
        return p[coord];
    else{
        std::cout << "Coordinate does not exist" << std::endl;
        return INT_FAST16_MIN;
    }
}

/**
 * Update specified coordinate of point
 * 
 * @param coord dimension that user wants to update (e.g. x -> 0, y -> 1, z -> 2,...)
 * @param val new value for dimension
*/
void Point::set_coordinate(int coord,int val){
    if (coord < p.size() && coord >= 0)
        p[coord] = val;
    else
        std::cout << "Coordinate does not exist" << std::endl; 
}


/**
 * Returns the euclidian distance between point the function is called on and point p2
 * Update: now works for points of arbitrary dimensions
 * 
 * @param p2 point we want to measure the distance to
 * @return euclidian distance between two points
*/
double Point::distance(Point p2){
    if (p.size() == p2.get_dimensions()){
        int sum = 0;
        for(int i = 0; i < p.size(); i++){
            sum += pow( (p[i] - p2.get_coordinate(i)) , 2 );
        }
        return sqrt(sum);
    }
    else{
        std::cout << "Dimensions don't match" << std::endl;
        return INT_FAST16_MIN;
    }
}

/**
 * moves all of the point's coordinates by dist given
 * Update: now works for points of arbitrary dimensions
 * 
 *@param dist distance to increment/decrement every coordinate 
*/
void Point::translate(int dist){
    for(int i = 0; i < p.size(); i++){
        p[i] += dist;
    }
}