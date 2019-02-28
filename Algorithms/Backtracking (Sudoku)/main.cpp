#include <iostream>
#include <cstring>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <windows.h>
#include <dos.h>
#include <dir.h>

using namespace std;

/*
    backtracking is a refinement of the brute force (exhaustive enumeration), in which
    a good part can be eliminated without being explicitly examined.
    It can be used in problems in which the solution can be defined from a sequence of
    decisions, and problems in which can be modeled by a tree that represents all possible
    sequence of decisions.

    Backtracking finds solutions by trying partial solutions and then abandoning them if they
    are not suitable.
    it's a "brute force" algorithm technique (tries all paths) that is often implemented recursively
    Applications:
        producing all permutations of a set of values
        parsing languages
        games: anagrams, crosswords, word jumbles, 8-queens problems
        combinatorics and logic programming
        escaping from a maze
    General pseudo-code:
        explore(decisions):
            if there are no more decisions:
                stop
            else
                we make one decision and the rest is done by recursion
                for each available choice c for this decision
                    choose c
                    explore the remaining choices that could follow c
                    UN-choose c (backtrack)
                ...
            ...
        ...
    ...
*/


/*
    This programs solves the Sudoku problem where given a grid 9x9,
    the goal is to assign digits (from 1 to 1) to the empty cells so that
    every row, column and subGrid of size 3x3 contains exactly one instance of the digits
    from 1 to 9.
    So we can have naive solution which generates all possibles configurations of numbers from 1 to 9 to fill the empty cells.
    trying every configuration one by one until it finds a solution.
    or we can use the backtracking technique.
    Using backtracking, before assign a number we first check if it's safe to assign a specific values in the specific row and col,
    checking if the number is present in the row, col and in the 3x3 grid, after check it, if it returns true means that it's safe,
    then we can put this number there and then explore other number combined with that partial solution, if this doesn't lead to a solution
    then we try the next number removing it the number that was been used from the solutions and assign another number in this current position.
    If none of the number from 1 to 9 leads to a solution we return false.
    the pseudo code algorithm wold be:

    Find row, col of an unassigned cell
    If there is none unassigned cells,
        return true // it was found a solution
    For digits from 1 to 9
        a) If there is no conflict for digit at row, col
            assign digit to row, col
            and recursively try fill in rest of grid
        b) If recursion successful, return true
        c) Else, remove digit and try another (backtracking)
    If all digits have been tried and nothing worked,
        return false
*/

// Function used to change color from terminal
void SetColor(int ForgC) {
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        //Mask out all but the background attribute, and add in the forgournd     color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

class Sudoku {
private:
    int grid[9][9] = {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    int numberOfSolutions;
public:
    // Initialize grid 9 by 9 with 0s
    Sudoku() {
       //memset(grid, 0, sizeof(grid[0][0])*81);
    }

    // Method to check if it's safe to place the number passed to the parameter
    // in the specified row and column
    bool isItSafe(int row, int col, int number) {
        // Checking the row, if there's conflict with the given number
        for (int i = 0; i < 9; i++) {
            if(grid[row][i] == number) // the given number was already placed in the row
                return false; // it's not possible place the number here
        }

        // Checking the col, if there's conflict with the given number
        for (int i = 0; i < 9; i++) {
            if(grid[i][col] == number) // the given number was already placed in the col
                return false; // it's not possible place it in the specified row and col
        }
        // Checking the 3 by 3 grid
        for (int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(grid[i + row - (row % 3)][j + col - (col % 3) ] == number) // if the number exists in the 3 by 3 grid
                    return false; // it's not possible place it here
            }
        }
        // Otherwise, it hasn't found any number that makes a conflicts, then it's possible use this number
        // in the specific row and col
        return true;
    }

    bool findEmptyLocation(int& row, int& col) {
        for (int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(grid[i][j] == 0) {
                    row = i;
                    col = j;
                    return true; // it has found an empty cell to place an number
                }
            }
        }
        // it hasn't found a place to place it
        return false;
    }

    bool solveSudoku() {
        // checking for empty place
        int row, col;
        // if it has not found an empty location, then the problem was solved
        if(!this->findEmptyLocation(row, col)) {
            this->showSudoku();
            return true; // return true, to specify that one possible solution were found
        } else {
            // checking all possible number from 0 to 9 to place in that col and row
            for (int number = 1; number <= 9; number++) {
                // choose
                // if it's safe to place the current number in the current row and col, then:
                if(this->isItSafe(row, col, number)) {
                    // place the current number in the current row and col
                    this->grid[row][col] = number;
                    // explore other partial solution combined with the current partial solution
                    if(solveSudoku())
                        return true; // it was found a solution so return true; we don't want here to generate all possible configurations
                    // in case it get here, it means that it's not possible using the current number in this row and col position
                    // to get to a solution
                    // UN-choose it (backtracking)
                    this->grid[row][col] = 0;
                }
            }

            // if it gets here, it means that it has tried all possible numbers from 1 to 9 and has checked all possible empty
            // cells and hasn't found a solution.
            return false;
        }
    }

    // Implement later to generate random Sudoku games void generateSudoku() {}

    // method to show personalized grid
    void showSudoku() {
        cout << ">>>>> S U D O K U <<<<<\n";
        cout << " =====================\n";
        for (int i = 0; i < 9; i++) {
            cout << " ";
            if(i == 3 || i == 6)
                cout << "---------------------\n ";
            for(int j = 0; j < 9; j++) {
                if(j != 0)
                    cout << " ";
                if(j == 3 || j == 6)
                    cout << "| ";
                cout << grid[i][j];
            }
            cout << endl;
        }
        cout << " =====================\n";
    }
};

int main()
{
    Sudoku game;
    SetColor(0);
    game.solveSudoku();
    return 0;
}
