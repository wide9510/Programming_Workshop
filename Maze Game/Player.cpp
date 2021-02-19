#include "Player.h"

Player::Player(const std::string name, const bool is_human){ //constructor
    name_ = name;
    is_human_ = is_human;
    points_ = 0;
    pos_.row = 0;
    pos_.col = 0;
} 

/** increments the current points of a player
*
* @param x number of points to add
*/
void Player::ChangePoints(const int x){
    points_ += x;
} 

/** change current position of player
*
* @param pos new position for player
*/
void Player::SetPosition(Position pos){
    pos_.row = pos.row;
    pos_.col = pos.col;
}

/** Converts coordinate directions to relative directions for player(e.g UP,DOWN,LEFT,RIGHT)
 * 
 * @param other position that player might move to 
 * @return string telling player relative direction(e.g UP,DOWN,LEFT,RIGHT)
*/
std::string Player::ToRelativePosition(Position other){
    std::string dir;
    if(pos_.row > other.row)
        dir = "UP";
    else if(pos_.row < other.row)
        dir = "DOWN";
    else if(pos_.col > other.col)
        dir =  "LEFT";
    else if(pos_.col < other.col)
        dir = "RIGHT";
    return dir;
}

//prints out a player's name and points
std::ostream& operator<<(std::ostream& os, const Player &p){
    os << p.get_name() << " has " << p.get_points() << "points.";
    return os;
}