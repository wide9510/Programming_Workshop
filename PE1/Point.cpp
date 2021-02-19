#include "Point.h"
#include <cmath>

/**
 * Constructor with no arguments
 * Creates point at origin (0,0)
*/
Point::Point() {
    x_ = 0;
    y_ = 0;
}

/**
 * Contructor with two arguments
 * creates point at (x_val,y_val)
 * 
 * @param x_val The x coordinate
 * @param y_val The y coordinate
*/
Point::Point(int x_val,int y_val){
    x_ = x_val;
    y_ = y_val;
}

/**
 * Returns the x coordinate of point
 * @return x coordinate
*/
int Point::get_x(){
    return x_;
}

/**
 * Returns the y coordinate of point
 * @return y coordinate
*/
int Point::get_y(){
    return y_;
}

/**
 * Update x coordinate of point
 * @param x_val new x coordinate
*/
void Point::set_x(int x_val){
    x_ = x_val;
}

/**
 * Update y coordinate of point
 * @param y_val new y coordinate
*/
void Point::set_y(int y_val){
    y_ = y_val;
}

/**
 * Returns the euclidian distance between point the function is called on and point p
 * 
 * @param p point we want to measure the distance to
 * @return euclidian distance between two points
*/
double Point::distance(Point p){
    return sqrt( pow((x_ - p.x_),2) + pow((y_ - p.y_),2)  );
}

/**
 * moves all of the point's coordinates by dist given
 * 
 *@param dist distance to move the x and y coordinates
*/
void Point::translate(int dist){
    x_ += dist;
    y_ += dist;
}