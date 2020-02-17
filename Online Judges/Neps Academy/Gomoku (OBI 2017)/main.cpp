#include <iostream>

using namespace std;

int v[15][15];

int check(int row, int col) {
    int b = 0, w = 0;
    // check lines backwards and forward if possible
    for (int i = row; (i < row + 5) && (row + 5 < 15); i++) {
        if (v[i][col] == 1)
            b++;
        if (v[i][col] == 2)
            w++;
    }

    if (w == 5 || b == 5)
        return w == 5? 2 : 1;

    w = b = 0;

    for (int i = row; (i > row - 5) && (row - 5 >= 0); i--) {
        if (v[i][col] == 1)
            b++;
        if (v[i][col] == 2)
            w++;
    }

    if (w == 5 || b == 5)
        return w == 5? 2 : 1;

    // check coll
    w = b = 0;

    for (int i = col; (i < col + 5) && (col + 5 < 15); i++) {
        if (v[row][i] == 1)
            b++;
        if (v[row][i] == 2)
            w++;
    }

    if (w == 5 || b == 5)
        return w == 5? 2 : 1;

    w = b = 0;

    for (int i = col; (i > col - 5) && (col - 5 >= 0); i--) {
        if (v[row][i] == 1)
            b++;
        if (v[row][i] == 2)
            w++;
    }

    if (w == 5 || b == 5)
        return w == 5? 2 : 1;

    // check diagonals (primary up, down, secondary up and down)

    w = b = 0;

    for (int i = row, j = col; i < (row + 5) && j < (col + 5) && (col + 5 <= 15) && (row + 5 <= 15); i++, j++) {
        if (v[i][j] == 1)
            b++;
        if (v[i][j] == 2)
            w++;
    }
   // cout << "Diag first for: " << row << " - " << col << " = w: " << w << " and b: " << b << endl;
    if (w == 5 || b == 5)
        return w == 5? 2 : 1;


    w = b = 0;

    for (int i = row, j = col; i > (row - 5) && j < (col + 5) && (col + 5 <= 15) && (row - 5 >= 0); i--, j++) {
        if (v[i][j] == 1)
            b++;
        if (v[i][j] == 2)
            w++;
    }

    if (w == 5 || b == 5)
        return w == 5? 2 : 1;


    w = b = 0;

    for (int i = row, j = col; i < (row + 5) && j > (col - 5) && (row + 5 <= 15) && (col - 5 >= 0); i++, j--) {
        if (v[i][j] == 1)
            b++;
        if (v[i][j] == 2)
            w++;
    }

    if (w == 5 || b == 5)
        return w == 5? 2 : 1;

    w = b = 0;
    for (int i = row, j = col; i > (row - 5) && j > (col - 5) && (row - 5 >= 0) && (col - 5 >= 0); i--, j--) {
        if (v[i][j] == 1)
            b++;
        if (v[i][j] == 2)
            w++;
    }

    if (w == 5 || b == 5)
        return w == 5? 2 : 1;

    return 0;
}

int main()
{
    int winner = 0;

    for (int i = 0; i < 15; i++) {
        for(int j = 0; j < 15; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < 15; i++) {
        for(int j = 0; j < 15; j++) {
            winner = check(i, j);
            if (winner) {
                break;
            }
        }
        if (winner)
            break;
    }
    cout << winner << endl;
    return 0;
}
