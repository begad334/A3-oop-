// File name:Integrated
// Purpose:Integrated program
// Author(s):Begad Abdelghafar_Dina Gamal_Ammar Mohamed
// ID(s):20220521_20221052_20220215
// Section:S8
// Date:17/12/2023
// Version:1
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include"BoardGame_Classes.hpp"
using namespace std;
// Set the board
X_O_Board::X_O_Board()
{
    n_rows = n_cols = 3;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++)
    {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool X_O_Board::update_board(int x, int y, char mark)
{
    // Only update if move is valid
    if (!(x < 0 || x > 2 || y < 0 || y > 2) && (board[x][y] == 0))
    {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

// Display the board and the pieces on it
void X_O_Board::display_board()
{
    for (int i : {0, 1, 2})
    {
        cout << "\n| ";
        for (int j : {0, 1, 2})
        {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool X_O_Board::is_winner()
{
    char row_win[3], col_win[3], diag_win[2];
    for (int i : {0, 1, 2})
    {
        row_win[i] = board[i][0] & board[i][1] & board[i][2];
        col_win[i] = board[0][i] & board[1][i] & board[2][i];
    }
    diag_win[0] = board[0][0] & board[1][1] & board[2][2];
    diag_win[1] = board[2][0] & board[1][1] & board[0][2];

    for (int i : {0, 1, 2})
    {
        if ((row_win[i] && (row_win[i] == board[i][0])) ||
            (col_win[i] && (col_win[i] == board[0][i])))
        {
            return true;
        }
    }
    if ((diag_win[0] && diag_win[0] == board[1][1]) ||
        (diag_win[1] && diag_win[1] == board[1][1]))
    {
        return true;
    }
    return false;
}

// Return true if 9 moves are done and no winner
bool X_O_Board::is_draw()
{
    return (n_moves == 9 && !is_winner());
}

bool X_O_Board::game_is_over()
{
    return n_moves >= 9;
}

//////////////////////////////////////
// X_O 5x5 board

X_O_fiveXfive_board::X_O_fiveXfive_board () {
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
bool X_O_fiveXfive_board::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}


void X_O_fiveXfive_board::display_board() {
    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n----------------------------------------------";
    }
    cout << endl;
}

bool X_O_fiveXfive_board::is_winner() {
    if (n_moves == 24) {
        int player1Count = 0;
        int player2Count = 0;

        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                char currentCell = board[i][j];

                switch (currentCell) {
                    case 'X':
                        if (check_row(i, j) || check_column(i, j) || check_diagonal1(i, j) || check_diagonal2(i, j)) {
                            player1Count++;
                        }
                        break;

                    case 'O':
                        if (check_row(i, j) || check_column(i, j) || check_diagonal1(i, j) || check_diagonal2(i, j)) {
                            player2Count++;
                        }
                        break;

                    default:
                        break;
                }
            }
        }

        if (player1Count == player2Count) {
            return false;
        } else {
            cout << player1Count << " " << player2Count;
            return true;
        }
    }

    return false;
}

bool X_O_fiveXfive_board::is_valid(int x, int y) {
    if (!(x < 0 || x > 4 || y < 0 || y > 4)) {
        return true;
    }
    return false;
}

bool X_O_fiveXfive_board::check_row(int x,int y){
    if(is_valid(x,y+1) && is_valid(x,y+2)){
        if(board[x][y] == board[x][y] && board[x][y+1] == board[x][y] && board[x][y+2] == board[x][y]){
            return true;
        }
        return false;
    }

}

bool X_O_fiveXfive_board::check_column(int x,int y){
    if(is_valid(x+1,y) && is_valid(x+2,y)){
        if(board[x][y] == board[x][y] && board[x+1][y] == board[x][y] && board[x+2][y] == board[x][y]){
            return true;
        }
        return false;
    }
}

bool X_O_fiveXfive_board::check_diagonal1(int x,int y){
    if(is_valid(x+1,y+1) && is_valid(x+2,y+2)){
        if((board[x][y] == board[x][y] && board[x+1][y+1] == board[x][y] && board[x+2][y+2] == board[x][y])){
            return true;
        }
        return false;
    }
}
bool X_O_fiveXfive_board::check_diagonal2(int x, int y) {
    if(is_valid(x+1,y-1) && is_valid(x+2,y-2)){
        if((board[x][y] == board[x][y] && board[x+1][y-1] == board[x][y] && board[x+2][y-2] == board[x][y])){
            return true;
        }
        return false;
    }
}
// Return true if 24 moves are done and no winner
bool X_O_fiveXfive_board::is_draw(){
    return (n_moves == 24 && !is_winner());
}

bool X_O_fiveXfive_board::game_is_over(){
    return (n_moves >= 24);
}
/////////////////////////////////////////////////////////
// code pyramic
// code pyramic
// Constructor
Pyramic_game::Pyramic_game() {
    n_rows = 3;
    n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];

        for (int j = 0; j < n_cols; j++) {
            board[i][j] = 0;
        }
    }
}

// Update board function
bool Pyramic_game::update_board(int x, int y, char mark) {
    // Only update if the move is valid
    if (((x == 0 && y == 2) || (x == 1 && (y >= 1 && y <= 3)) || (x == 2 && (y >= 0 && y <= 4))) && (board[x][y] == 0)) {
        board[x][y] = std::toupper(mark);
        n_moves++;
        return true;
    } else {
        return false;
    }
}

// Display board function
void Pyramic_game::display_board() {
    cout << "              | " << board[0][2] << " (0,2) |" << "\n";
    cout << "_____________________________\n";
    cout << "       |" << board[1][1] << " (1,1) |" << board[1][2] << " (1,2) |" << board[1][3] << " (1,3) |\n";
    cout << "_____________________________\n";
    cout << board[2][0] << " (2,0) |" << board[2][1] << " (2,1) |" << board[2][2] << " (2,2) |" << board[2][3] << " (2,3) |" << board[2][4] << " (2,4)\n";
    cout << "_____________________________\n";
}


// Check if there is a winner
bool Pyramic_game::is_winner() {
    // Rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][2] == board[i][3] && board[i][3] == board[i][4] && board[i][4] != 0) {
            return true;
        }
    }

    // Columns
    for (int j = 0; j < 3; ++j) {
        if (board[0][j + 2] == board[1][j + 2] && board[1][j + 2] == board[2][j + 2] && board[2][j + 2] != 0) {
            return true;
        }
    }

    // Diagonals
    if (board[0][2] == board[1][3] && board[1][3] == board[2][4] && board[2][4] != 0) {
        return true;
    }
    if (board[2][2] == board[1][3] && board[1][3] == board[0][4] && board[0][4] != 0) {
        return true;
    }

    return false;
}


// Check if it's a draw
bool Pyramic_game::is_draw() {
    if (n_moves == 9) {
        return !is_winner();
    }
    return false;
}


// Check if the game is over
bool Pyramic_game::game_is_over() {
    return n_moves > 8;
}
/////////////////////////////////////////////////////
Four_Board::Four_Board(){
    n_rows=6;n_cols=7;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;

    }

}

bool Four_Board::update_board (int x, int y, char mark){
    // Only update if move is valid
    x=0;
    if (!(y < 0 || y > 6 ) ) {
        int cnt1=6,cnt2=6,cnt3=6,cnt4=6,cnt5=6,cnt6=6,cnt7=6;
        if(y==0){
            cnt1--;
            board[cnt1][y] = toupper(mark);
            n_moves++;
            return true;

        }
        if(y==1){
            cnt2--;
            board[cnt2][y] = toupper(mark);
            n_moves++;
            return true;

        }
        if(y==2){
            cnt3--;
            board[cnt3][y] = toupper(mark);
            n_moves++;
            return true;

        }
        if(y==3){
            cnt4--;
            board[cnt4][y] = toupper(mark);
            n_moves++;
            return true;

        }
        if(y==4){
            cnt5--;
            board[cnt5][y] = toupper(mark);
            n_moves++;
            return true;

        }
        if(y==5){
            cnt6--;
            board[cnt6][y] = toupper(mark);
            n_moves++;
            return true;

        }
        if(y==6){
            cnt7--;
            board[cnt7][y] = toupper(mark);
            n_moves++;
            return true;

        }




    }
    else
        return false;
}


void Four_Board::display_board() {
    for (int i: {0,1,2,3,4,5}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4,5,6}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------------------------------";
    }
    cout << endl;
}


bool Four_Board::is_draw() {
    return (n_moves ==42  && !is_winner());
}


bool Four_Board::game_is_over () {
    return n_moves >= 42;
}
bool Four_Board::is_winner(){
//char row_win1[4], col_win1[4], diag_win1[4];
    for(int i=0;i<6;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==board[i][j+1]==board[i][j+2]==board[i][j+3] && board[i][j]!=0){
                return true;
            }
        }

    }
    for(int j=0;j<7;j++ ){
        for(int i=0;i<2;i++){
            if(board[i][j]==board[i+1][j]==board[i+2][j]==board[i+3][j]&& board[i][j]!=0)
                return true;
        }
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            if(board[i][j]==board[i+1][j+1]&& board[i][j]!=0)
                return true;
            if(board[i][j]==board[i+1][j-1]&& board[i][j]!=0)
                return true;
        }
    }
    return false;
}
