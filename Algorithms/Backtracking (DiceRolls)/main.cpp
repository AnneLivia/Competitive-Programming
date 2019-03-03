#include <iostream>
#include <vector>

using namespace std;

/*
    Combinatorial problems:
        Those are the ones in which a solution is a combination of a
        subset of elements.
        The search space of a combinatorial problem is a set with all
        possible solutions, being it restrict to the viable solutions or not
            - One viable solution is a complete solution that attends the
            requisites of the problem.
            - One not viable solution is a incomplete solution or null solution
        We also can have equivalent solutions, that is, more than one viable
        solution for same problem.
        some problems have only one better solution than all others, calling it an
        optimal solution.
    Try and error, brute force or exhaustive search is the strategy more trivial and
    intuitive for the solutions to the problems.

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
    Write a recursive function that accepts an integer representing a number of
    6-sided dice to roll, and output all possible combinations of values that could appear
    on the dice.
*/

ostream& operator << (ostream& stream, vector<int>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        if(i != 0)
            stream << ", ";
        stream << v[i];
    }
    return stream;
}

void rollDiceHelper(vector<int>& v, int dice, string space = "") {
    // There's no dice left (base case)
    // die, dice
    cout << space << "rollDiceHelper( {" << v << "}, " << dice << ")\n";
    if(dice == 0) {
        cout << space << "->> (" << v << ")" << endl;
    } else {
        // There are some dice left to roll
        // handle one dice
        // for each value that a die could have (from 1 to 6)
        for (int i = 1; i <= 6; i++) {
            // choose
            v.push_back(i); // save the dice that were choose
            // explore the ones that can be combined with it
            rollDiceHelper(v, dice - 1, space + " ");
            // UN-choose, returns from where it was before (backtrack)
            v.erase(v.end() - 1, v.end()); // removing the last one that was added to the vector
        }
    }
}

void rollDice(int dice) {
    vector<int>v;
    rollDiceHelper(v, dice);
}

int main()
{
    rollDice(3);
    return 0;
}
