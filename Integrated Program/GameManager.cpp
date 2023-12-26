// File name:Integrated
// Purpose:Integrated program
// Author(s):Begad Abdelghafar_Dina Gamal_Ammar Mohamed
// ID(s):20220521_20221052_20220215
// Section:S8
// Date:17/12/2023
// Version:1

#include <iostream>
#include"BoardGame_Classes.hpp"
using namespace std;

GameManager::GameManager(Board* bPtr, Player* playerPtr[2] ) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void GameManager::run() {
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
            players[i]->get_move(x, y);
            while (!boardPtr->update_board (x, y, players[i]->get_symbol())){
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()){
                cout  << players[i]->to_string() << " wins\n";
                return;
            }
            if (boardPtr->is_draw()){
                cout << "Draw!\n";
                return;
            }
        }
    }
}

void GameManager::run_connect() {
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
            players[i]->get_move_connect(x, y);
            while (!boardPtr->update_board (x, y, players[i]->get_symbol())){
                players[i]->get_move_connect(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()){
                cout  << players[i]->to_string() << " wins\n";
                return;
            }
            if (boardPtr->is_draw()){
                cout << "Draw!\n";
                return;
            }
        }
    }
}

void GameManager::run5x5(){
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
            players[i]->get_move_5x5(x, y);
            while (!boardPtr->update_board (x, y, players[i]->get_symbol())){
                players[i]->get_move_5x5(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()){
                if(X_O_fiveXfive_board::player1_winner()){
                    cout << players[0]->to_string() << " " << "wins\n";
                }
                else{
                    cout << players[1]->to_string() << " " << "wins\n";
                }
            }
            if (boardPtr->is_draw()){
                cout << "Draw!\n";
                return;
            }
        }
    }
}