// File name:Integrated
// Purpose:Integrated program
// Author(s):Begad Abdelghafar_Dina Gamal_Ammar Mohamed
// ID(s):20220521_20221052_20220215
// Section:S8
// Date:17/12/2023
// Version:1


#include <iostream>
#include "BoardGame_Classes.hpp"

using namespace std;

void playGame(GameManager& game, Player* players[2]) {
    game.run();
    system("pause");
    delete players[0];
    delete players[1];
}

Player* getPlayer(int playerNumber, char symbol, int boardSize) {
    int choice;
    cout << " 1 to play vs computer and 2 to play vs  a friend: ";
    cin >> choice;
    if (choice != 1)
        return new Player(playerNumber, symbol);
    else {
        return new RandomPlayer(symbol, boardSize);
    }
}

int main() {
    system("cls");
    int choice;
    const int boardSizes[4] = { 3, 5, 3, 7 };

    while (true) {
        cout << "\n wich game do you want to play :\n";
        cout << "1. X-0 [3*3]\n";
        cout << "2. X-0 [5*5]\n";
        cout << "3. PYrAmIc\n";
        cout << "4. connect four\n";
        cout << "5. ESC\n";
        cout << "choose from  (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4: {
                Player* players[2];
                players[0] = new Player(1, 'x');
                players[1] = getPlayer(2, 'o', boardSizes[choice - 1]);

                GameManager* game;
                if (choice == 1) {
                    game = new GameManager(new X_O_Board(), players);
                } else if (choice == 2) {
                    game = new GameManager(new X_O_fiveXfive_board(), players);
                } else if (choice == 3) {
                    game = new GameManager(new Pyramic_game(), players);
                } else if (choice == 4) {
                    game = new GameManager(new Four_Board (), players);
                }

                playGame(*game, players);
                delete game;
                break;
            }
            case 5: {
                cout << "GG\n";
                return 0;
            }
            default: {
                cout << "Error. you need to choose a number between one and five.\n";
                break;
            }
        }
    }
    return 0;
}
