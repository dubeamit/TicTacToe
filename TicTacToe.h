/* create a 4x4 game board
   prompt first user(x) to enter their name
   prompt second user(o) to enter their name
   prompt user 'x' To select a position in grid
   prompt user 'o' To select a position in grid
   After each user has a turn, check for any row, col, diag, that has 4 'x's of 4'o's
   if 4'x's found first player wins else if 4 'o's second user wins
   Declare winner and end game
   if 8 turns are over and no one wins declare tie */

#include <iostream>
#include <string>

using namespace std;

class TicTacToe{
    // array to contain player names
    string playerName[2]; 

    //Grid
    string board[4][4];

public:
    TicTacToe();  

    void setPlayerName(string, int);

    string getPlayerName(int);

    int setPosition(int,int,char);

    void printGrid();
    
    int checkWinCondition(int);
    
};