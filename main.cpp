#include "TicTacToe.h"

int main(){
    int moves = 0;
    int row_pos, col_pos;
    TicTacToe t;
    string player1, player2;
    cout << "\nEnter the names of player1 & player2 " << endl;
    cin >> player1 >> player2;
    t.setPlayerName(player1,0);
    t.setPlayerName(player2,1);
    
    while(moves < 16){
        if(moves%2 == 0){
            cout << "\nPlayer1 enter position: ";
            cin >> row_pos >> col_pos;
            if(t.setPosition(row_pos,col_pos,'X')){
                continue;
            }
            t.printGrid();
            if(t.checkWinCondition(moves)){
                cout << "\nPlayer "<<t.getPlayerName(0)<< " has won " << endl;
                break;
            }
        }
        else
        {
            cout << "\nPlayer2 enter position: ";
            cin >> row_pos >> col_pos;
            if(t.setPosition(row_pos,col_pos,'O')){
                continue;
            }
            t.printGrid();
            if(t.checkWinCondition(moves)){
                cout << "\nPlayer "<<t.getPlayerName(1)<< " has won " << endl;
                break;
            }
        }

        moves++;
        
    }
    
    return 0;

}