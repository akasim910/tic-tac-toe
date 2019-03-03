//#include "game_logic.cpp"
#include "tic_tac_toe.h"
#include <iostream>
#include <cctype>
using namespace std;

int main(){
    char user_choice;
    cout << "***********************" << endl;
    cout << "Welcome to Tic Tac Toe" << endl;
    cout << "***********************" << endl << endl;

    // lets user choose piece
    do //executes what's under the 'do' at least one time
    {
        cout << "Please choose your piece (X / O) ";
        cin >> user_choice; 
        user_choice = toupper(user_choice); //converts choice to uppercase
    }
    while(user_choice != 'O' && user_choice != 'X');

    
    TicTacToe t(user_choice); //create an object of the class
    cout << endl << "Your choice is: " << user_choice << endl;
    
    // while loop to run the game
    while(true) //keeps going until condition is false
    {
        t.print_board(); //prints board
        t.user_move();    //user move
        t.computer_move(); // computer move
        t.check_winner(); //checks to see winner
        if (t.get_game_over() == true) //prints board one more time and breaks while loop
        {
            t.print_board();
            break;
        }
        else if(t.check_tie() == true)
        {
            t.print_board();
            cout << "-------------------" << endl;
            cout << "GAME OVER : TIE" << endl;
            
            break;
        }
    }

    
    
    
    
    
    
    
    return 0;
}