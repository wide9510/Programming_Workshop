/** William Dellinger
 * Identikey: 109222219
 * Homework 1: Simple maze game
 * For improving the game I implemented option #4, turn count restriction for human
 * Additional Notes: For extra credit i gave the enemies a very basic movement strategy a.k.a random
*/
#include "Player.h"
#include "Maze.h"
#include <iostream>
#include<time.h>

int main(){
    srand(time(NULL));
    std::cout << "WELCOME TO MAZE!" << std::endl;
    std::cout << "Enter your name: ";
    std::string in;
    std::cin >> in;
    std::cout << std::endl;

    Player human(in,true);

    Maze maze;
    maze.NewGame(&human,3); //make sure second parameter is equal to number of enemies
    while(maze.IsGameOver() == false){
        maze.TakeTurn(maze.GetCurrentPlayer());
        maze.GetNextPlayer();
    }

}