#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>
#include <cstdlib>
#include <chrono>

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
    N queens problems:
        The N Queen is the problem of placing N chess queens on an N x N
        chessboard so that no two queens attack each other.
    8 queens problems:
        place 8 queens on a chess board such that no queen can attack another queen.

    The queens move horizontally, vertically and diagonally
    (both main diagonal and secondary diagonal)

    For 4 queens, one possible solution would be:
    -> 0 1 0 0
    -> 0 0 0 1
    -> 1 0 0 0
    -> 0 0 1 0

    OBS: each row has one queen, which means that in a working solution, exactly 1 queen
    must appear in each row and in each column.

    pseudo-code get from geeks for geeks website:
    1) Start in the leftmost column
    2) If all queens are placed
        return true
    3) Try all rows in the current column.
       Do following for every tried row.
        a) If the queen can be placed safely in this row then mark this [row,
        column] as part of the solution and recursively check if placing queen here
        leads to a solution.
        b) If placing the queen in [row, column] leads to a solution then return
        true.
        c) If placing queen doesn't lead to a solution then UN-mark this [row,
        column] (Backtrack) and go to step (a) to try other rows.
    3) If all rows have been tried and nothing worked, return false to trigger
    backtracking (there's no solution since if the queen couldn't be placed in this row
    since in the N queen problems in a feasible solution all cols have exactly one queen,
    then it's not possible to have a good solution for this board).
*/

string& operator * (string& s, int number) {
    char c = s[0];
    for (int i = 0; i < number; i++) {
        s+=c;
    }
    return s;
}

string& operator *= (string& s, int number) {
    return s * number;
}

class ChessBoard {
private:
    vector<vector<int> > board;
    int boardSize;
    int feasibleSolutions = 0;
public:
    ChessBoard(int boardSize) : boardSize(boardSize) {
        // Creating a chess board of size boardSize of rows and cols
        this->board.assign(boardSize, vector<int>(boardSize, 0));
    }

    // Updating boardSize
    void setBoardSize(int boardSize) {
        this->boardSize = 0;
        board.assign(boardSize, vector<int>(boardSize, 0));
    }

    int getBoardSize() const {
        return this->boardSize;
    }

    int getFeasibleSolutions() const {
        return this->feasibleSolutions;
    }

    // Checking if the row and col position passed is safe
    bool isSafe(int row, int col) {
        // since I'm placing the queen in each of the cols starting from 0
        // then it's guaranteed that the current col is safe, so we need only to
        // check the row and the diagonals, since there's none queen from col to the right
        // we can only check from 0 to the number of cols in which queens are placed

        // Checking horizontal (row)
        for (int i = 0; i < col; i++) {
            if(this->board[row][i] == 1) // there's already one queen here
                return false; // it's not safe then
        }

        // checking first diagonal (left since to the right there's any queen placed yet)
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if(this->board[i][j] == 1)
                return false; // it's not safe
        }

        // checking secondary diagonal (left since to the right there's any queen placed yet)
        for (int i = row, j = col; i < this->boardSize && j >= 0; i++, j--) {
            if(this->board[i][j] == 1)
                return false; // it's not safe
        }

        // If it got here, then any from the queens already placed
        // was found on the board
        return true;
    }

    // place queen at the specified position
    void placeQueen(int row, int col) {
        this->board[row][col] = 1;
    }

    // remove queen from the specified position
    void removeQueen(int row, int col) {
        this->board[row][col] = 0;
    }

    // function to solve the n queens problems where those queens must be
    // placed on the board such that any of them attack each other
    // if it finds a solution the function should stop
    void solveQueensProblem() {
        helperSolveQueensProblem(0);
    }

    // solving N queens problem using the column reference
    void helperSolveQueensProblem(int column) {
        // if the column is greater of equal to the size of the board
        // it means that I've already placed all queen in each column
        if(column >= this->boardSize) {
            // return true; // if the program only need to check if there's solution or not
            feasibleSolutions++;
            cout << feasibleSolutions << "th solution:\n";
            // print solution found
            showBoard();
            system("pause");
        } else {
            // There's must have one queen placed in this column
            // check each possible place in this column
            for (int row = 0; row < this->boardSize; row++) {
                // if this row and column is safe to place a queen
                if(this->isSafe(row, column)) {
                    // place a queen here
                    this->placeQueen(row, column);
                    // showing algorithm placing queen
                    this->showBoard();
                    this_thread::sleep_for(chrono::milliseconds(1500));
                    system("cls");
                    // explore other possible solution
                    // if(this->helperSolveQueensProblem(column + 1)) // if it return true from here, then stop it too
                    this->helperSolveQueensProblem(column + 1);
                    // displace the queen from this current position
                    // on the board (backtracking)
                    this->removeQueen(row, column);
                }
            }
        }

        // return false; // if the queen cannot be placed in any row in this column, then return false since there's no solution
    }

    void showBoard() {
        cout << " N Queens problem:\n";
        string line = "=";
        int decrease;
        if(this->boardSize % 2 == 0)
            decrease = 2;
        else
            decrease = 1;
        line*=this->boardSize + (this->boardSize / 2) * 2 - decrease;
        cout << " " << line << endl;
        for (int i = 0; i < this->boardSize; i++) {
            for(int j = 0; j < this->boardSize; j++) {
                cout << " ";
                if(this->board[i][j])
                    cout << "Q";
                else
                    cout << "-";
            }
            cout << "\n";
        }
        cout << " " << line << endl;
    }
};


int main()
{
    ChessBoard queens(10);
    queens.solveQueensProblem();
    cout << "There were: " << queens.getFeasibleSolutions() << endl;
    return 0;
}
