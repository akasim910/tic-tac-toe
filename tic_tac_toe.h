#include <iostream>
#include <string>
using namespace std;
// created a class for the game tic tac toe
#ifndef tic_tac_toe_h
#define tic_tac_toe_h

class TicTacToe{
public:
    //default constructor
    TicTacToe();
    TicTacToe(char);
    
    //getters
    void print_board(); //prints game board
    char get_user_choice(); //gets user choice (X or O)
    bool get_game_over(); //get game state (whether game is over or not)
    bool check_winner(); //checks to see if the user or the computer won
    bool check_tie(); //checks to see if there is a tie
    
    
    //setters
    void user_move(); //user turn
    void computer_move(); //computer turn
    
    
    
private:
    char board[3][3]; //game board represents 2-D array
    char user_choice; //user choice (X or O)
    bool game_over; //game state (Is it over or not?)
    
};


#endif