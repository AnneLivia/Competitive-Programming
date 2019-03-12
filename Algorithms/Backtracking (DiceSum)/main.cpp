#include <iostream>
#include <vector>

using namespace std;

/*
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
    Write a function that accepts an integer representing a number of
    6-sided dice to roll and one number that represents a desirable sum,
    and output all possible combinations of values that could add up to exactly
    that sum.
*/

ostream& operator << (ostream& stream, vector<int>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        if(i != 0)
            stream << ", ";
        stream << v[i];
    }
    return stream;
}

int calls = 0;

void diceSumHelper(vector<int>&v, int dice, int sum, int sumSoFar = 0, string space = "") {
    calls++; // Total number of calls
    cout << space << "rollDiceHelper( {" << v << "}, " << dice << ", " << sumSoFar << ")\n";
    // Base case, it was found the desirable sum and the number of dice left is 0
    // sum is equal to zero, because we can decrease the sum variable the rolled dice
    // and if it get to zero, we've found one combination
    if(dice == 0) {
        cout << space << " ->> (" << v << ") = " << sum << endl;
    } else {
        // There are some dice left to roll
        // handle one dice
        // for each value that a die could have (from 1 to 6)
        for (int i = 1; i <= 6; i++) {
            // If the sum reached so far is less than the desirable one
            // sumSoFar + i <= sum and dice > 0 makes 240 calls when we have 4 dices and we want only
            // the ones that combined reaches the sum of 9
            // just make calls where the sum is not too big neither too small
            if(sumSoFar + i + 1 * (dice - 1) <= sum &&
               sumSoFar + i + 6 * (dice - 1) >= sum) {
                // Pick one dice and save it into the vector
                v.push_back(i);
                // explore the ones that can be combined with it and its sum is not greater than the desirable one
                diceSumHelper(v, dice - 1, sum, sumSoFar + i, space + " ");
                // remove the chosen one from the vector (backtrack)
                // it cannot be explored more
                v.erase(v.end() - 1, v.end()); // remove the last one added
            }
        }
    }
}

void diceSum(int dice, int sum) {
    vector<int>v;
    diceSumHelper(v, dice, sum);
}
int main()
{
    diceSum(4, 9);
    cout << "Total number of calls: " << calls << endl;
    return 0;
}
