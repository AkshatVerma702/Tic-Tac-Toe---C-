#include<bits/stdc++.h>
using namespace std;

string player1;
string player2;
string board[5][5];

void display_board(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j <5; j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
}


void reset_board(){
    //Initialize Spaces
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            board[i][j] = "  ";
        }
    }

    //Make board skeleton
    for(int i = 0; i < 5; i = i + 2){
        for(int j = 1; j < 5; j+=2){
            board[i][j] = "|";
        }
    }

    for(int i = 1; i < 5; i = i + 2){
        for(int j = 0; j < 5; j++){
            if(j % 2 == 0){
                board[i][j] = "--";
            }
            else{
                board[i][j] = "+";
            }
        }
    }
}

void setup_board(){
    reset_board();
    display_board();
}

bool check_winner(char mark){
    
    string m = " " + string(1,mark);

    // Check rows
    for (int i = 0; i < 5; i += 2) {
        if (board[i][0] == m && board[i][2] == m && board[i][4] == m) return true;
    }

    // Check columns
    for (int i = 0; i < 5; i += 2) {
        if (board[0][i] == m && board[2][i] == m && board[4][i] == m) return true;
    }

    // Check diagonals
    if (board[0][0] == m && board[2][2] == m && board[4][4] == m) return true;
    if (board[0][4] == m && board[2][2] == m && board[4][0] == m) return true;

    return false;
}

int game_start(string player1, string player2){
    bool p1_turn = true;
    int move = 1;
    while (move <= 9) {
        cout << (p1_turn ? player1 : player2) + "'s Turn" << endl;
        int row, col;
        cout << "Enter the coordinates (1-3) where you want to play your move (row and column): " << endl;
        cin >> row >> col;

        char mark = (p1_turn ? 'X' : 'O');

        // Convert 1-indexed input to 0-indexed internal board representation
        row = (row - 1) * 2;
        col = (col - 1) * 2;

        if (row < 0 || row >= 5 || col < 0 || col >= 5 || board[row][col] != "  ") {
            cout << "Invalid Move. Try again." << endl;
            continue;
        } else {
            board[row][col] = " " + string(1, mark);
            display_board();
        }

        if (check_winner(mark)) {
            return (p1_turn ? 1 : 2);
        }

        move++;
        p1_turn = !p1_turn; 
    }

    return 0; 
}


int main(){
    while (true) {
        setup_board();
        cout << "Player-1(X) name?: ";
        cin >> player1;
        cout << "Player-2(O) name?: ";
        cin >> player2;

        int winner = game_start(player1, player2);

        if (winner == 0) {
            cout << "It's a Draw!!!" << endl;
        } else if (winner == 1) {
            cout << "Player - 1 " + player1 + " Wins!!" << endl;
        } else {
            cout << "Player - 2 " + player2 + " Wins!!!" << endl;
        }

        string restart;
        cout << "Play Again?(Yes / No): ";
        cin >> restart;

        if (restart != "Yes" && restart != "yes") {
            break;
        }
    }

    cout << "Thank You For Playing!!!!";
    return 0;
}
