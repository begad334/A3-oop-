// File name:Integrated
// Purpose:Integrated program
// Author(s):Begad Abdelghafar_Dina Gamal_Ammar Mohamed
// ID(s):20220521_20221052_20220215
// Section:S8
// Date:17/12/2023
// Version:1
#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"BoardGame_Classes.hpp"
using namespace std;

// Set player symbol and name as Random Computer Player
RandomPlayer::RandomPlayer (char symbol, int dimension):Player(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

// Generate a random move
void RandomPlayer::get_move (int& x, int& y) {
    x = (int) (rand()/(RAND_MAX + 1.0) * dimension);
    y = (int) (rand()/(RAND_MAX + 1.0) * dimension);
}

void RandomPlayer::get_move_connect (int& x, int& y) {
    x = (int) (rand()/(RAND_MAX + 1.0) * dimension);
    y = (int) (rand()/(RAND_MAX + 1.0) * dimension);
}

void RandomPlayer::get_move_5x5 (int& x, int& y) {
    x = (int) (rand()/(RAND_MAX + 1.0) * dimension);
    y = (int) (rand()/(RAND_MAX + 1.0) * dimension);
}
