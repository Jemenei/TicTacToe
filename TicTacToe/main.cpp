#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void drawBoard(char *spaces) {
    cout << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    cout << "     |     |     " << '\n';
    cout << '\n';
}


void playerMove(char *spaces, char player) {
    int number;
    do {
        cout << "Enter a spot to place a marker (1-9): ";
        cin >> number;
        number--;
        if (spaces[number] == ' ') {
            spaces[number] = player;
            break;
        }
    } while (true);
}


void computerMove(char *spaces, char computer) {
    int number;
    srand(time(0));

    while (true) {
        number = rand() % 9;
        if (spaces[number] == ' ') {
            spaces[number] = computer;
            break;
        }
    }
}


bool checkWinner(char *spaces, char player, char computer) {
    const int winPatterns[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, 
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, 
        {0, 4, 8}, {2, 4, 6}             
    };

    for (int i = 0; i < 8; i++) {
        int a = winPatterns[i][0];
        int b = winPatterns[i][1];
        int c = winPatterns[i][2];

        if (spaces[a] != ' ' && spaces[a] == spaces[b] && spaces[b] == spaces[c]) {
            if (spaces[a] == player) {
                cout << "YOU WIN!\n";
            } else {
                cout << "YOU LOSE!\n";
            }
            return true;
        }
    }

    return false;
}

// Функция для проверки ничьей
bool checkTie(char *spaces) {
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            return false;
        }
    }
    cout << "IT'S A TIE!\n";
    return true;
}

int main() {
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces);

    while (running) {
        playerMove(spaces, player);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer)) {
            running = false;
            break;
        } else if (checkTie(spaces)) {
            running = false;
            break;
        }

        computerMove(spaces, computer);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer)) {
            running = false;
            break;
        } else if (checkTie(spaces)) {
            running = false;
            break;
        }
    }
    cout << "Thanks for playing!\n";

    return 0;
}
