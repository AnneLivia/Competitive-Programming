#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

/*
    The knapsack problem or rucksack problem is a problem
    in combinatorial optimization: Given a set of items,
    each with a weight and a value, determine the number
    of each item to include in a collection so that the
    total weight is less than or equal to a given limit
    and the total value is as large as possible.

    This is a problem that can be used dynamic programming,
    Which is a method of dynamic programming, which is also sometimes
    referred to as "dynamic optimization" is an approach to
    solving complex problems by breaking the down into their smaller parts,
    and storing the result to these subproblems so that they only need to be
    computed once.

    Dynamic program has two approaches:
        Bottom-up (start solving smallest problems, to after that solve largest problems
        Top-down (start solving the largest ones, so that it solves the smallest ones)


    The algorithm is basically in this way:
    first, check if with the weight of the current index is possible to add it in the backpack by,
    checking if the weight in the current time is greater or equal to the current row weight, if it's not
    then assign 0, otherwise, check if the greater number, if it is the above number or the above number, one column to the left
    + the value of the current weight and assign it to the position

    Example from https://www.ime.usp.br/~pf/analise_de_algoritmos/aulas/mochila-bool.html
    Maximum weight of the backpack: 5

    Array of weights and values:
    weight [ 4,   2,   1,   3  ]
    value  [500, 400, 300, 450 ]

    Starting with weight 0:
    Can weight 0 be inserted in a backpack of weight 0, no, there's now weight, neither backpack...
    Can weight 0 be inserted in a backpack of weight 1, no, there's no weight there, the value to be inserted in the table in this case is 0
    Now, weight 1:
    Can weight 1(4) be inserted in a backpack of weight 0, no, 1 (4) is heavier than 0.
    Can weight 1(4) be inserted in a backpack of weight 1, no, 1 (4) is heavier than 1.
    Can weight 1(4) be inserted in a backpack of weight 2, no, 1 (4) is heavier than 2.
    Can weight 1(4) be inserted in a backpack of weight 3, no, 1 (4) is heavier than 3.
    Can weight 1(4) be inserted in a backpack of weight 4, yes, 1 (4) is equal to 4, so in this position will be inserted the maximum of: (above row in the same col, or above row, col of number (current col - (current weight)), plus the value of the current weight).
                    (In this case, the above one is 0, and (current col - (current weight)) is 0 + the current weight which is 500, the maximum is 500, then insert it there)
    Can weight 1(4) be inserted in a backpack of weight 5, yes, 1(4) is lesser than 5, so take the maximum (above row (0) or,(current col - (current weight) col 1, has (0) + current value (500))

    Now, weight 2:
    Can weight 2(2) be inserted in a backpack of weight 0, no, 2 (2) is heavier than 0.
    Can weight 2(2) be inserted in a backpack of weight 1, no, 2 (2) is heavier than 1.
    Can weight 2(2) be inserted in a backpack of weight 2, yes, 2 (2) is equal to 2. max(above row or above row, col - current weight col);
    Can weight 2(2) be inserted in a backpack of weight 3, no, 2 (2) is lighter than 3.
    Can weight 2(2) be inserted in a backpack of weight 4, no, 2 (2) is lighter than 4.
    Can weight 2(2) be inserted in a backpack of weight 5, no, 2 (2) is lighter than 5.

    Now, weight 3:
    Can weight 3(1) be inserted in a backpack of weight 0, no, 3 (1) is heavier than 0.
    Can weight 3(1) be inserted in a backpack of weight 1, yes, 3 (1) is equal to 1. max(above row or above row, col - current weight col);
    Can weight 3(1) be inserted in a backpack of weight 2, yes, 3 (1) is equal to 2. max(above row or above row, col - current weight col);
    Can weight 3(1) be inserted in a backpack of weight 3, yes, 3 (1) is lighter than 3. max(above row (400) or above row, col - current weight col + value (400 + 300 = 700);
    Can weight 3(1) be inserted in a backpack of weight 4, yes, 3 (1) is lighter than 4.
    Can weight 3(1) be inserted in a backpack of weight 5, yes, 3 (1) is lighter than 5.

    Same step above is done now to weight 4 (3)

    That's the table:

        0     1     2     3     4     5

(0) 0   0     0     0     0     0     0

(4) 1   0     0     0     0    500   500

(2) 2   0     0    400   400   500   500

(1) 3   0    300   400   700   700   800

(3) 4   0    300   400   700   750   850

*/

int MaxBackPack = 100; // Maximum weight of the backpack
int maxNumberOfObj = 200; // Maximum number of objects

int knapsack(int *vetWeight, int *vetValue, int nVet, int wtMax) {
    // nVet is for weights and values
    // wtMax is the maximum weight of the backpack

    int table[nVet + 1][wtMax + 1]; // This 2D array goes from 0..size, and 0..wtMax

    // Insert 0 in all cols of the first position, because 0 element can't be inserted in the backpack
    for(int i = 0; i < wtMax + 1; i++)
        table[0][i] = 0;
    // Insert 0 in all rows of the first col, since, whatever weight there is, is the backpack doesn't support any weight, then it mustn't be inserted
    for(int i = 0; i < nVet + 1; i++)
        table[i][0] = 0;

    int solution = 0; // here will be store exactly number to be stored


    for(int i = 1; i < nVet + 1; i++) { // It will start from the second row of the table, since in the first is weight 0

        for(int j = 1; j < wtMax + 1; j++) {
            solution = table[i - 1][j]; // First the possible solution to this one is the weight in the row above the current one.
            // If weight of this current row is less equal to the current col position, this can be inserted in the backpack
            if(vetWeight[i - 1] <= j) {
                int value = table[i - 1][j - (vetWeight[i - 1])] + vetValue[i - 1]; // Getting the sum of the the current object with the above line at the j - weight col
                if(value > solution) { // If the result is greater then
                    // insert in the current position of the table
                    solution = value;
                }
            }
            table[i][j] = solution; // insert the right solution in the current row and col
        }
    }

    /*
        Steps to find the best possible combination:
        in the last col, go to the last row and check if it is different of the above one, if it is, then it was added in the backpack,
        otherwise, it wasn't then, go up one row until find it, when found, insert it somewhere like a vector, and then,
        subtract the current col that represents a weight with the weight of the current position, and goes to the above row, in the subtract result col,
        and repeat the first step, check if the current row, col is different of the above row, col.
    */

    vector<int>usedWeights; // vector to store the objects inserted in the backpack

    int i = nVet; // Starting from the last row
    int j = wtMax; // Starting from the last col

    // While the value inserted there is different of 0, since it is 0, it means that that weight or object wasn't added in the backpack because it doesn't fit there
    while(table[i][j]) {
        // If the above value is different of the current one, it was added in the backpack
        if(table[i - 1][j] != table[i][j]) {
            usedWeights.push_back(vetWeight[i - 1]); // insert the weight in the backpack
            j = (j - vetWeight[i - 1]); // update col to the col that is needed to complete the sum.
        }

        i--; // decrement row.
    }
    cout << "Used weights: \n\n";
    for(int i = 0; i < (int)usedWeights.size(); i++)
        cout << usedWeights[i] << " ";
    cout << endl << endl;

    cout << "Table of value: \n\n";
    for (int i = 0; i < nVet + 1; i++) {
        for(int j = 0; j < wtMax + 1; j++) {
            cout << setw(5) << table[i][j];
        }
        cout << endl;
    }

    cout << endl;

    return table[nVet - 1][wtMax - 1]; // return the last row, last col value, since there is being stored the maximum sum that can used in the backpack
}

int main()
{
    int values[4] = {1, 4, 5, 7};
    int weights[4] = {1, 3, 4, 5};

    int answer = knapsack(weights, values, 4, 7);


    cout << "Maximum value is: " << answer;
    return 0;
}
