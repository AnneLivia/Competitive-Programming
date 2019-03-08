#include <iostream>
#include <vector>
#include <string>
#include <set>

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
    Write a function that accepts a string as a parameter and outputs
    all possible rearrangements of the letters in that string. the arrangements
    may be output in any order.
*/

void permuteStringHelper(string word, string chosen, set<string>& alreadyPrinted, string space = "") {
    cout << space + "Word: " << word << ", chosen: " << chosen << endl;
    // base case, there's none character left to choose
    if(word.empty()) {
        // In order to not print the repeated ones
        if(alreadyPrinted.find(chosen) == alreadyPrinted.end()) {
            cout << chosen << endl;
            alreadyPrinted.insert(chosen);
        }
    } else {
        for (int i = 0; i < (int)word.size(); i++) {
            // choose letter
            char c = word[i];

            // insert it as one of the chosen ones
            chosen+=word[i];

            // explore other possible solution that can be combined with the picked char
            word.erase(i, 1); // removing it from string
            permuteStringHelper(word, chosen, alreadyPrinted, space + " ");

            // UN-choose letter (backtrack)
            word.insert(i, 1, c);
            chosen.erase(chosen.length() - 1, 1);
        }
    }
}

void permuteString(string word) {
    set<string> chosen;
    permuteStringHelper(word, "", chosen);
}

int main()
{
    permuteString("ANNE");
    return 0;
}
