#include <iostream>
using namespace std;

// Масив для дошки
char board[9];

// Глобальна змінна — хто зараз ходить
char currentPlayer = 'X';

// Функція ініціалізації дошки числами 1-9
void initBoard() {
    for (int i = 0; i < 9; ++i) {
        board[i] = '1' + i;
    }
}

// Вивід дошки
void printBoard() {
    cout << "=========" << endl;
    for (int i = 0; i < 9; i += 3) {
        cout << board[i] << " " << board[i+1] << " " << board[i+2] << endl;
    }
    cout << "=========" << endl;
}

// Хід гравця
void playerMove(char player) {
    cout << "Spieler " << player << ", gib eine Koordinate (1-9): ";
    char move{};
    cin >> move;

    if (move >= '1' && move <= '9') {
        int index = move - '1';

        if (board[index] != 'X' && board[index] != 'O') {
            board[index] = player;
        } else {
            cout << "Feld schon besetzt! Versuche erneut." << endl;
            playerMove(player);
        }
    } else {
        cout << "Ungültige Eingabe! Bitte 1-9." << endl;
        playerMove(player);
    }
}

// Перевірка на перемогу
void checkWin(char player) {
    if (
        (board[0] == player && board[1] == player && board[2] == player) ||
        (board[3] == player && board[4] == player && board[5] == player) ||
        (board[6] == player && board[7] == player && board[8] == player) ||
        (board[0] == player && board[3] == player && board[6] == player) ||
        (board[1] == player && board[4] == player && board[7] == player) ||
        (board[2] == player && board[5] == player && board[8] == player) ||
        (board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player)
    ) {
        printBoard();
        cout << "Spieler " << player << " hat gewonnen!" << endl;
        exit(0);
    }
}

// Перевірка на нічию
void checkDraw() {
    for (int i = 0; i < 9; ++i) {
        if (board[i] != 'X' && board[i] != 'O') {
            return; // ще є вільне поле
        }
    }
    printBoard();
    cout << "Unentschieden!" << endl;
    exit(0);
}

// Зміна гравця
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    initBoard(); // лише один раз на початку

    while (true) {
        printBoard();
        playerMove(currentPlayer);
        checkWin(currentPlayer);
        checkDraw();
        switchPlayer();
    }

    return 0;
}