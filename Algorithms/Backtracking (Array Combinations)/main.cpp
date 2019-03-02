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
    Generating all combinations of a given array, example:
    Array = [1,2,3]
    Combinations:
        [1,2,3] -> (We cannot have [2,1,3] or [3,1,2] and others because in combination those are all the same, it doesn't care about orders)
        [1,2] -> Same as above, it doesn't care about orders, so [2,1] is the same
        [1,3] -> Same as above
        [1]
        [2,3] -> same as above
        [2]
        [3]
    ...
*/
ostream& operator << (ostream& stream, vector<int>& vec) {
    for (int i = 0; i < (int)vec.size(); i++) {
        if(i != 0)
            stream << ", ";
        stream << vec[i];
    }
    return stream;
}

void combinationHelper(vector<int>& vec, vector<int>& soFar, string space = "") {
    cout << space << "CombinationHelper([" << vec << "],[" << soFar << "]);\n";
    // Base case, when vec is empty and we cannot choose any other element from it
    if(vec.empty()) {
        cout << "[" << soFar << "]" << endl;
    } else {
        // Choose, explore, UN-choose
        // One side of the tree has the first element, the other note
        // Get the first element
        int firstElement = vec[0];
        // remove it from the vector
        vec.erase(vec.begin(), vec.begin() + 1);
        // insert it on the soFar vector
        soFar.push_back(firstElement);
        // explore it
        combinationHelper(vec, soFar, space + " ");
        // UN-choose it
        // we don't have the number
        soFar.erase(soFar.end() - 1, soFar.end());
        // Explore it
        combinationHelper(vec, soFar, space + " ");
        // Insert the element again in the VEC vector (backtracking)
        vec.insert(vec.begin(), firstElement);
    }
}

void combination2(vector<int>& vec, vector<int>& isOn, int i) {
    // base case, if i is equal to size
    if(i == (int)vec.size()) {
        // print all elements that is true in the vector isOn
        cout << "[";
        for (int i = 0; i < (int)vec.size(); i++) {
            if(isOn[i]) {
                cout << vec[i] << " ";
            }
        }
        cout << "]" << endl;
    } else {
        // With it
        isOn[i] = true;
        // Explore with it
        combination2(vec, isOn, i + 1);
        // Without it
        isOn[i] = false;
        // Explore without it
        combination2(vec, isOn, i + 1);
    }
}

void combination(vector<int>& vec) {
    vector<int> soFar;
    combinationHelper(vec, soFar);
}

int main()
{
    vector<int> v = {1,2,3};
    combination(v);
    //vector<int> isOn = {0,0,0};
    //combination2(v,isOn,0);
    return 0;
}
