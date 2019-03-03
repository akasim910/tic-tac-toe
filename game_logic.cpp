#include "tic_tac_toe.h"

TicTacToe::TicTacToe(){
    /*
    Default contructor for TicTacToe class
    */
    for (int i = 0; i < 3; i++) //creates board and puts period in every spot of board
    {
        for (int j = 0; j < 3; j++ )
        {
            board[i][j] = '.';
        }
    }
                  
    game_over = false;
}


TicTacToe::TicTacToe(char c){
    /*
    Constructor for class TicTacToe with char argument
    */
    for (int i = 0; i < 3; i++) //sets user choice equal to c
    {
        for (int j = 0; j < 3; j++ )
        {
            board[i][j] = '.';
        }
    }
    
    user_choice = c;         
    game_over = false;
}

void TicTacToe:: print_board(){
    /*
    Prints game board
    */
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " " << board[i][j];
        }
        cout << endl;
    }

}

void TicTacToe:: user_move(){
    /*
    Asks user for input of row and column and places piece inside the 2d Array
    */
    int row, col;
    cout << "Please enter row of move (1-3): ";
    cin >> row;
    cout << endl << "Please enter column of move (1-3): ";
    cin >> col;
    cout << endl;
    if(user_choice == 'X') //makes the move, puts X or 0 in its spot
    {
        board[row - 1][col - 1] = 'X';  
    }
    else if(user_choice == 'O')
    {
        board[row - 1][col - 1] = 'O';
    }
    
    
}




void TicTacToe::computer_move(){
    /*
    This function makes the move for the computer. If the center piece is empty, it places the piece there. After that
    it checks to see if there are any spots where the user can win (2 in a row or sandwiched pieces) and places a piece to prevent that
    */
    int dir[8][2] = {{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}}; //2-D array that has all the directions it can check (8 ways), first priority to place piece where user can win to prevent user
    char cpuChoice = user_choice == 'O' ? 'X' : 'O';
    bool move_made = false;
    if(true)
    {
        for (int i = 0; i < 3 && move_made == false; i++)
        {
            for (int j = 0; j < 3 && move_made == false; j++)
            {
            
                for(int a = 0; a < 8 && move_made == false; a++) //checks if user's piece has two pieces in a row and checks the last spot
                {
                   int x = i + dir[a][0];
                   int y = j + dir[a][1];
                   int nextX = x + dir[a][0];
                   int nextY = y + dir[a][1];
                   if(x < 0 || x > 2 || y < 0 || y > 2)
                   {
                       continue;
                   }
                   else
                   {
                       if(board[x][y] == user_choice && board[i][j] == user_choice)
                       {
                            if(nextX < 0 || nextX > 2 || nextY < 0 || nextY > 2)
                            {
                                continue;
                            }
                            else if(board[nextX][nextY] == '.')
                                {
                                    board[nextX][nextY] = cpuChoice;
                                    move_made = true;
                                }
                       } else if(board[x][y] == '.' && board[i][j] == user_choice){
                           int rightX;
                           int rightY; 
                           rightY = y+dir[a][1];
                            rightX = x+dir[a][0];
                            if(rightX < 0 || rightX > 2 || rightY < 0 || rightY > 2){
                                continue;
                            } else if(board[rightX][rightY] == user_choice){
                                board[x][y] = cpuChoice;
                                move_made = true;
                            } else {
                                continue;
                            }
                       }
                   }
                }
            }
        }
    }
    
    if(!move_made)
    {
        if(board[1][1] == '.') { //places move in the middle first then in all the corners
            board[1][1] = cpuChoice;
        }
        else if(board[0][0] == '.')
        {
            board[0][0] = cpuChoice;
        }
        else if(board[0][2] == '.')
        {
            board[0][2] = cpuChoice;
        }
        else if(board[2][0] == '.')
        {
            board[2][0] = cpuChoice;
        }
        else if(board[2][2] == '.')
        {
            board[2][2] = cpuChoice;
        }
        else {
            for (int i = 0; i < 3; i++) //places piece in a random spot if nothing else works
            {
                for (int j = 0; j < 3; j++ )
                {
                    if(board[i][j] == '.')
                    {
                        board[i][j] = cpuChoice;
                        return;  
                    }
                }
            }
        }
    }
}


bool TicTacToe:: check_tie(){
    /*
    Checks to see if the game is a tie
    */

    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
          if (board[i][j] == 'X' or board[i][j] == 'O')
          {
              continue;    
          }
          else if(board[i][j] == '.')
          {
              return false;
          }
      }
      
    }
    return true;
}



bool TicTacToe:: check_winner(){
    /*
    This function goes through the board and checks to see if there is a winner
    */

    if (user_choice == 'X') //checks if there is a winner and checks all possible iterations, checks if your piece is X 
    {
        if (board[0][0] == 'X' and board[0][1] == 'X' and board[0][2] == 'X')
        {
            cout << "You win!" << endl;
            game_over = true;
        }
        else if (board[1][0] == 'X' and board[1][1] == 'X' and board[1][2] == 'X')
        {
            cout << "You win!" << endl;
            game_over = true;
        }
        else if (board[2][0] == 'X' and board[2][1] == 'X' and board[2][2] == 'X')
        {
            cout << "You win!" << endl;
            game_over = true;
        }
        else if (board[0][0] == 'X' and board[1][1] == 'X' and board[2][2] == 'X')
        {
            cout << "You win!" << endl;
            game_over = true;
        }
        else if (board[2][0] == 'X' and board[1][1] == 'X' and board[0][2] == 'X')
        {
            cout << "You win!" << endl;
            game_over = true;
        }
        else if (board[0][0] == 'X' and board[1][0] == 'X' and board[2][0] == 'X')
        {
            cout << "You win!" << endl;
            game_over = true;
        }
        else if (board[0][1] == 'X' and board[1][1] == 'X' and board[2][1] == 'X')
        {
            cout << "You win!" << endl;
            game_over = true;
        }
        else if (board[0][2] == 'X' and board[1][2] == 'X' and board[2][2] == 'X')
        {
            cout << "You win!" << endl;
            game_over = true;
        }
        // these next check for the computer's piece, whether it has won
        else if (board[0][0] == 'O' and board[0][1] == 'O' and board[0][2] == 'O')
        {
            cout << "The computer wins!" << endl;
            game_over = true;
        }
        else if (board[1][0] == 'O' and board[1][1] == 'O' and board[1][2] == 'O')
        {
            cout << "The computer wins!" << endl;
            game_over = true;
        }
        else if (board[2][0] == 'O' and board[2][1] == 'O' and board[2][2] == 'O')
        {
            cout << "The computer wins!" << endl;
            game_over = true;
        }
        else if (board[0][0] == 'O' and board[1][1] == 'O' and board[2][2] == 'O')
        {
            cout << "The computer wins!" << endl;
            game_over = true;
        }
        else if (board[2][0] == 'O' and board[1][1] == 'O' and board[0][2] == 'O')
        {
            cout << "The computer wins!" << endl;
            game_over = true;
        }
        else if (board[0][0] == 'O' and board[1][0] == 'O' and board[2][0] == 'O')
        {
            cout << "The computer wins!" << endl;
            game_over = true;
        }
        else if (board[0][1] == 'O' and board[1][1] == 'O' and board[2][1] == 'O')
        {
            cout << "The computer wins!" << endl;
            game_over = true;
        }
        else if (board[0][2] == 'O' and board[1][2] == 'O' and board[2][2] == 'O')
        {
            cout << "The computer wins!" << endl;
            game_over = true;
        }
        else
        {
        }
        
        
    }
    
    else if (user_choice == 'O') //checks if there is a winner and checks all possible iterations, checks if your piece is O
    {
        if (board[0][0] == 'O' and board[0][1] == 'O' and board[0][2] == 'O')
        {
            cout << "You win!" << endl;
            game_over = true;
        }
        else if (board[1][0] == 'O' and board[1][1] == 'O' and board[1][2] == 'O')
        {
            cout << "You win!" << endl;
            game_over = true;
        }
        else if (board[2][0] == 'O' and board[2][1] == 'O' and board[2][2] == 'O')
        {
            cout << "You win!" << endl;
            game_over = true;
        }
        else if (board[0][0] == 'O' and board[1][1] == 'O' and board[2][2] == 'O')
        {
            cout << "You win!" << endl;
            game_over = true;
        }
        else if (board[2][0] == 'O' and board[1][1] == 'O' and board[0][2] == 'O')
        {
            cout << "You win!" << endl;
            game_over = true;
        }
        else if (board[0][0] == 'O' and board[1][0] == 'O' and board[2][0] == 'O')
        {
            cout << "You win!" << endl;
            game_over = true;
        }
        else if (board[0][1] == 'O' and board[1][1] == 'O' and board[2][1] == 'O')
        {
            cout << "You win!" << endl;
            game_over = true;
        }
        else if (board[0][2] == 'O' and board[1][2] == 'O' and board[2][2] == 'O')
        {
            cout << "You win!" << endl;
            game_over = true;
        }
        
        else if (board[0][0] == 'X' and board[0][1] == 'X' and board[0][2] == 'X')
        {
            cout << "The computer wins!" << endl;
            game_over = true;
        }
        else if (board[1][0] == 'X' and board[1][1] == 'X' and board[1][2] == 'X')
        {
            cout << "The computer wins!" << endl;
            game_over = true;
        }
        else if (board[2][0] == 'X' and board[2][1] == 'X' and board[2][2] == 'X')
        {
            cout << "The computer wins!" << endl;
            game_over = true;
        }
        else if (board[0][0] == 'X' and board[1][1] == 'X' and board[2][2] == 'X')
        {
            cout << "The computer wins!" << endl;
            game_over = true;
        }
        else if (board[2][0] == 'X' and board[1][1] == 'X' and board[0][2] == 'X')
        {
            cout << "The computer wins!" << endl;
            game_over = true;
        }
        else if (board[0][0] == 'X' and board[1][0] == 'X' and board[2][0] == 'X')
        {
            cout << "The computer wins!" << endl;
            game_over = true;
        }
        else if (board[0][1] == 'X' and board[1][1] == 'X' and board[2][1] == 'X')
        {
            cout << "The computer wins!" << endl;
            game_over = true;
        }
        else if (board[0][2] == 'X' and board[1][2] == 'X' and board[2][2] == 'X')
        {
            cout << "The computer wins!" << endl;
            game_over = true;
        }
        else
        {
        } 
        
    }
    
}





bool TicTacToe::get_game_over(){ //returns whether the game is over or not
    /*
    Returns state of game
    */
    return game_over;
}

char TicTacToe::get_user_choice(){ //returns user's move, O or X
    /*
    Returns user choice
    */
    return user_choice;
}