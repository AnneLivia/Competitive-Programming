#include <iostream>
#include <vector>

using namespace std;

/*
    Exhaustive search: exploring every possible combination from a set of choices or values
    Often implemented recursively
    Applications:
        Producing all permutations of a set of values
        enumerating all possible names, passwords, etc.
        combinatorics and logic programming
    Backtracking:
        It's an algorithm technique for finding all (or some) solutions
        to some computational problems, that incrementally builds candidates
        to the solutions, and as soon as it finds an elements that is not a valid
        solution it goes backwards to find another possible one.
        Backtracking can be used for listing all possible solutions for a combinatorial
        algorithm problem. It basically iterate through all the possible configurations of
        a search space. These configurations may be either all possible arrangements of objects
        (permutation) or all possible ways of building a collection of them (subsets).
        Those possible configurations are generated exactly once.
        Backtracking ensures correctness by enumerating all possibilities.
        It ensures efficiency by never visiting a state more than once.
    General pattern for exhaustive search:
        Search(decision):
            if there are no more decisions to make: stop
            else, let's handle one decision ourselves, and the rest by recursion
            for each available choice C for this decision:
                choose C
                search the remaining decisions that could follow C.
    Problem:
        Write a function that accepts an integer number of
        digits and prints all binary numbers that have exactly
        that many digits, in ascending order, one per line.
*/

void printBinary(int number, string b = "", string space = "") {
    /*
        Assuming number passed to the function is 3
        printBinary(3, "")
            printBinary(2,"0") -> "" + "0"
                printBinary(1,"00") "0" + "0"
                    printBinary(0,"000") -> "00" + "0"
                    printBinary(0,"001") -> "00" + "1"
                printBinary(1,"01") -> "0" + "1"
                    printBinary(0,"010") -> "01" + "0"
                    printBinary(0,"011") -> "01" + "1"
            printBinary(2,"1") -> "" + "1"
                printBinary(1,"10") -> "1" + "0"
                    printBinary(0,"100") -> "10" + "0"
                    printBinary(0,"101") -> "10" + "1"
                printBinary(1,"11") -> "1" + "1"
                    printBinary(0,"110") -> "11" + "0"
                    printBinary(0,"111") -> "11" + "1"
                ...
            ...
        ...
    */

    /*
        Tree of calls: call tree or decision tree where each call is a choice or decision
        made by the algorithm.
                2   ,  " "
               /          \
           1,"0"         1,"1"
         /     \       /     \
       0,"00" 0,"01" 0,"10"  0,"11"

    */
    // Base case: if there are no more decisions to make
    cout << space << "PrintBinary(" << number << ", " << b << ")\n";
    if(number == 0) {
       cout << "->>> " << b << endl;
    } else {
        printBinary(number - 1, b + "0", space + " ");
        printBinary(number - 1, b + "1", space + " ");
    }
}
// printing all base-10 numbers in ascending order with one specific number of digits passed via parameter
void printDecimal(int number, string d = "", string space = "") {
    cout << space << "printDecimal(" << number << ", " << d  << ")\n";
    if(number == 0) {
        cout << "->>>>> " << d << endl;
    } else {
        for (int i = 0; i < 10; i++) {
            printDecimal(number - 1, d + to_string(i), space + " ");
        }
    }
}

int main()
{
    cout << "Print binary: ";
    printBinary(3);
    cout << "Print decimal: \n";
    printDecimal(3);
    return 0;
}
