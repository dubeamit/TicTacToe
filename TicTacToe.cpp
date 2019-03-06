#include "TicTacToe.h"

/***************
 * INITALIZE THE TIC-TAC-TOE GRID WITH INDICES FOR EACH ELEMENT
 ***************/
TicTacToe::TicTacToe(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            board[i][j] = to_string(i)+to_string(j);
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
}
/********************
 *  PRINT THE TIC-TAC-TOE GRID
*********************/
void TicTacToe::printGrid(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
}

void TicTacToe::setPlayerName(string name, int pos){
    playerName[pos] = name;
}

string TicTacToe::getPlayerName(int pos){
    return playerName[pos];
}

/********************
 *  CHECK FOR VALID POSITIONS
 *  CHECK IF POSITIONS ARE NOT BEEN OVERWRITEN 
*********************/

int TicTacToe::setPosition(int row, int col, char ch){

    if(row > -1 && row < 4){
        if(col > -1 && col < 4){
            if(board[row][col] != "X" && board[row][col] != "O"){
                board[row][col]=ch;
                return 0;
            }
            else{
                cout << "\n Position already filled please select an appropriate position" << endl;
                return 1;
            }
        }else
        {
            cout << "\nplease enter col in range of 0-3";
            return 1;
        }
        
    }else
    {
        cout << "\nplease enter row in range of 0-3";
        return 1;
    }
}

/********************
 *  CHECK FOR WIN CONDITIONS
*********************/

int TicTacToe::checkWinCondition(int moves){
    int row, col, rightDiagonal, leftDiagonal;
    int lcount;
    for(int i = 1; i < 4; i++){
        row = 0; col = 0; rightDiagonal = 0; leftDiagonal = 0;
        lcount = 2;
        for(int j = 1; j < 4; j++){
            if(board[i-1][j-1] == board[i-1][j]){
                row++;
            }
            else if(board[j-1][i-1] == board[j][i-1]){
                col++;
            }
            else if(board[j-1][j-1] == board[j][j])
            {
                rightDiagonal++;
            }
            else if(board[j-1][lcount+1] == board[j][lcount]){
                leftDiagonal++; 
            }
            lcount--; 
            
        }
        
        if(row == 3){
            return 1;  
        }
        else if(col == 3){
            return 1;   
        }
        else if (rightDiagonal == 3)
        {
            return 1;
        }
        else if (leftDiagonal == 3)
        {
            return 1;   
        }
        else if (moves > 9)
        {
            cout << "Game ended in draw " << endl;
            return 1;
        }        
        
    }
    return 0;
}