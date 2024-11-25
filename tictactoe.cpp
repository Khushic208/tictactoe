#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char token = 'x';
string n1, n2;
bool tie = false;

void fun1() {
    for (int i = 0; i < 3; i++) {
        cout << "     |     |     \n";
        cout << "  " << board[i][0] << "  |  " << board[i][1] << "  |   " << board[i][2] << "   \n";
        if (i < 2) {
            cout << "_____|_____|_____\n";
        }
    }
    cout << "     |     |     \n";
}

void fun2() {
    int digit;
    bool input = false;

    while (!input) {
        cout << (token == 'x' ? n1 : n2) << ", enter any digit from (1-9): ";
        cin >> digit;

        if (digit < 1 || digit > 9) {
            cout << "\nInvalid! Try again.\n";
            continue;
        }

        int row = (digit - 1) / 3;
        int column = (digit - 1) % 3;

        if (board[row][column] != 'x' && board[row][column] != '0') {
            board[row][column] = token;
              token = (token == 'x') ? '0' : 'x';

            input = true;
        } else {
            cout << "\nSpace already occupied! Try again.\n";
        }
    }
    fun1();
}

bool fun3() {
    // Check rows and columns for win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    // Check diagonals for win
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

    // Check for tie
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'x' && board[i][j] != '0') return false;
        }
    }
    tie = true;
    return false;
}

int main() {
    cout << "Enter the name of first player: ";
    cin >> n1;
    cout << "Enter the name of second player: ";
    cin >> n2;

    fun1();

    while (!fun3()) {
        fun2();
    }

    if (tie) {
        cout << "It's a draw!\n";
    } else {
        cout << (token == 'x' ? n1 : n2) << " wins!\n";
    }

    return 0;
}
