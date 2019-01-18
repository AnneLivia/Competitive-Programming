#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
// this variant of the coin change problem gives the number of ways
// some coins can be combined to give a specific change N
// to perform those calculations we must have an array of size N so that
// we can compute the optimal solution for its N subproblems, and then combine
// them to get the number of ways.

int coin_change_ways(int coins[], int n_coins, int change) {
    vector<int>table;
    table.assign(change + 1, 0);

    // First we need to set the first element of the array to 1,
    // because there's 1 way to make the number 0, when we don't have
    // any elements

    table[0] = 1;

    // Now we run through all the coins and compare the elements to the array
    // that we store the number of ways, so that we can determine how many times
    // each coin can be used to a specific index of the array. (compute all optimal solutions
    // of its subproblems)

    for(int j = 0; j < n_coins; j++) {
        for (int i = 0; i < change + 1; i++) {
            if(coins[j] <= i)  // if I can use this coins, then:
                table[i] += table[i - coins[j]]; // Increment the current i, with the other number that can be combined with it
        }
    }

    return table[change];
}

int main() {
    int vet[3] = {1,5,10}, change = 12; // Coins
    cout << coin_change_ways(vet, 3, change) << endl;
    return 0;
}
