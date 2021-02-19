#include "Maze.h"
#include <string.h>
#include <stdlib.h>  
#include <time.h> 
#include <ctype.h> 
#include <iostream>

/** convert square types into unicode tiles
 * 
 * @param sq square to convert
 * @return unicode tile
*/
std::string SquareTypeStringify(SquareType sq){
    std::string square;
    switch(sq) {
        case SquareType(0): 
            square = "❌";
            break;
        case SquareType(1):
            square = "✅";
            break;
        case SquareType(2):
            square = "⬜️";
            break;
        case SquareType(3):
            square = "🦉";
            break;
        case SquareType(4):
            square =  "🤡";
            break;
        case SquareType(5):
            square = "🍐";
            break;
    }
    return square;

}

/** Board Constuctor
 * 1. Generate exit,walls,and treasure
 * 2. Add players onto board
 * @param players used to add players to the board
*/
Board::Board(std::vector<Player *> players){
    //Generate exit,walls,and treasure
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4;j++){
            int rng = rand()%10 +1;
            //Exit at bottom right
            if(i == 3 && j == 3){
                arr_[i][j] = SquareType(1);
            }
            else{
                if(rng == 3)
                    arr_[i][j] = SquareType(5);
                else if(rng < 3)
                    arr_[i][j] = SquareType(0);
                else
                    arr_[i][j] = SquareType(2);
            }
        }
    }
    //Add players onto board
    for(int i = 0; i < players.size();i++){
        Position pos = players[i]->get_position();
        if(players[i]->is_human() == true){
            arr_[pos.row][pos.col] = SquareType(3);
        }
        else{
            arr_[pos.row][pos.col] = SquareType(4);
        }
    }
}

/** return square type of position on board
 * 
 * @param pos piece on board that you would like to know about
 * @return Square Type of position
*/
SquareType Board::get_square_value(Position pos) const{
    return arr_[pos.row][pos.col];
}

/** Set board at position pos to SqaureType value
 * 
 * @param pos position at which we are going to change value
 * @param value value we are changing it to
*/
void Board::SetSquareValue(Position pos, SquareType value){
    arr_[pos.row][pos.col] = value;
}

/** return vector of possible moves
 * 
 * @param *p pointer to a player whose potential moves we will look at
 * @return list of possible moves
*/
std::vector<Position> Board::GetMoves(Player *p){
    std::vector<Position> moves;
    Position pos = p->get_position();

    Position left;
    Position right;
    Position up;
    Position down;

    bool left_valid = false;
    bool right_valid = false;
    bool up_valid = false;
    bool down_valid = false;

    left.col = pos.col -1;
    left.row = pos.row;
    
    right.col = pos.col + 1;
    right.row = pos.row;

    up.col = pos.col;
    up.row = pos.row -1;
    
    down.col = pos.col;
    down.row = pos.row +1;

    //check that we are still on the board
    if(left.col >= 0)
        left_valid = true;
    if(right.col <= 3)
        right_valid = true;
    if(up.row >= 0)
        up_valid = true;
    if(down.row <= 3)
        down_valid = true;

    //check that its not a wall and not off the board
    if( (get_square_value(left) != SquareType(0)) && left_valid)
        moves.push_back(left);
    //check that its not a wall and not off the board
    if((get_square_value(right) != SquareType(0)) && right_valid){
        //check that it is not a enemy trying to move to the exit
        if( (p->is_human() == false) && (get_square_value(right) == SquareType(1))){}
        else
            moves.push_back(right);
    }
    //check that its not a wall and not off the board
    if((get_square_value(up) != SquareType(0)) && up_valid)
        moves.push_back(up);
    //check that its not a wall and not off the board
    if((get_square_value(down) != SquareType(0)) && down_valid)
    {
         //check that it is not a enemy trying to move to the exit
        if(( p->is_human() == false) && (get_square_value(down) == SquareType(1))){}
        else
            moves.push_back(down);
    }
    return moves;
}

/** move the player and update board
 * 
 * @param *p player that we are moving
 * @param pos position we are moving him to
*/
void Board::MovePlayer(Player *p, Position pos){
    //do nothing if enemy tries to move on a square another enemy already is on
    if( (p->is_human() == false) && (get_square_value(pos) == SquareType(4))){
    }
    else{
        SetSquareValue(p->get_position(),SquareType(2)); //replace current position with blank
        p->SetPosition(pos); //update position
        //if enemy collect treasure
        if(get_square_value(pos) == SquareType(5)){
            p->ChangePoints(100);
        }

        //update board with new tiles
        if(p->is_human() == true)
            SetSquareValue(pos,SquareType(3));
        else
            SetSquareValue(pos,SquareType(4));

    }
}

/** return square type on last tile
 * if exit occupant is the player we will call end game
 * @return square type on last tile
*/
SquareType Board::GetExitOccupant(){
    return arr_[get_rows()-1][get_cols()-1];
}

//used to print out board
std::ostream& operator<<(std::ostream& os, const Board &b){
    for(int i = 0; i < 4;i++){
        for(int j = 0; j < 4;j++){
            os << SquareTypeStringify(b.arr_[i][j]);
        }
        os << std::endl;
    }
    return os;
}

Maze::Maze(){  //default constructor
}

/** 
 * Initialize board
 * Initialize enemies
 * 
 * @param human pointer to human player
*/
void Maze::NewGame(Player *human, const int enemies){
    if(enemies > 4){
        std::cout << "Too many enemies!"<< std::endl;
        exit(EXIT_FAILURE);
    }
    turns_left_ = 7;
    turn_count_ = 0;
    players_.push_back(human);

    Player *en1 = new Player("Enemy1",false);
    Position pos0;
    pos0.row = 0;
    pos0.col = 3;
    en1->SetPosition(pos0);

    Player *en2 = new Player("Enemy2",false);
    Position pos1;
    pos1.row = 3;
    pos1.col = 0;
    en2->SetPosition(pos1);

    //initialize more players here

    players_.push_back(en1);
    players_.push_back(en2);
    //make sure to add them to the vector of players

    board_ = new Board(players_);
    game_over_ = false;

}
/** manage a players turn
 * separate rules for human and enemy ai turn
 * @param p player whose turn it is
*/
void Maze::TakeTurn(Player *p){
    bool valid_input= false;
    std::string input;
    std::string formatted_input = "";
    std::vector <std::string> options;
    //human turn
    if(p->is_human() == true){
        std::vector<Position> moves = board_->GetMoves(p);
        //loop that waits for valid user input
        while(valid_input == false){
            std::cout << p->get_name() << " has " << turns_left_ << " turns left" << std::endl;
            std::cout << p->get_name() << " can go:";
            //shows user their relative move options
            for(int i = 0; i < moves.size();i++){
                options.push_back(p->ToRelativePosition(moves[i]));
                std::cout << p->ToRelativePosition(moves[i]) + " ";
            }
            std::cout << std::endl;
            std::cout << *board_; //print board
            std::cout << "Please enter your choice: ";
            std::cin >> input;
            //convert all input to uppercase to avoid case sensitivity 
            for(int i = 0; i < input.length();i++){
                formatted_input += toupper(input[i]);
            }
            // std::cout << "formatted: " << formatted_input << std::endl;
            //check that direction selected is valid
            for(int i = options.size()-1; i >= 0 ;i--){
                if(formatted_input == options[i]){
                    board_->MovePlayer(p,moves[i]);
                    valid_input = true;
                }
                options.pop_back();
            }
            formatted_input = "";
            std::cout << std::endl;
        }
        //if player and enemy are on same tile end game
        for(int i = 1; i < players_.size();i++){
            if( (p->get_position() == players_[i]->get_position()) && (players_[i]->is_human() == false)){
                game_over_ = true;
            }
        }
        turns_left_--;
        //additional rules for ending game
        if(turns_left_ == 0 || board_->GetExitOccupant() == SquareType(3)){
            game_over_ = true;
            p->ChangePoints(1);
        }
    }
    //enemy turn
    else{
        std::cout << "It's " << p->get_name() << " turn" << std::endl;
        std::vector<Position> moves = board_->GetMoves(p);
        std::cout << p->get_name() << " can go:";
        for(int i = 0; i < moves.size();i++){
            options.push_back(p->ToRelativePosition(moves[i]));
            std::cout << p->ToRelativePosition(moves[i]) + " ";
        }

        //the following is for a simple enemy ai that picks randomly from available options
        int size = moves.size();
        if(size > 0){
            int rng = rand()%size;
            board_->MovePlayer(p,moves[rng]);
            std::cout << "Enemy went " << options[rng] << std::endl;
        }
        std::cout << std::endl <<  *board_;
        
        
    }
    //end game print out
    if(game_over_ == true){
        std::cout << "GAME OVER" << std::endl;
        for(int i = 0; i < players_.size();i++){
            std::cout << *players_[i] << std::endl;
        }
    }
    
}
// increment counter tracking which players turn it is
void Maze::GetNextPlayer(){

    if(turn_count_ == players_.size()-1)
        turn_count_ = 0;
    else
        turn_count_++;
}
//returns status of game_over_
bool Maze::IsGameOver(){
    return game_over_;
}
