#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
    Content from: https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/tutorial/
    The coin change problem:
    The coin change problem consist to find the combination with the
    minimum number of coins in which sum is equal to a determined quantity.
    using a list of valid coins that pursue infinity availability.

    Greedy algorithms (This is not an algorithm, it is a technique.)

    A greedy algorithm is an algorithmic paradigm that follows the
    problem solving heuristic of making the locally optimal choice
    at each stage with the intent of finding a global optimum.

    A greedy algorithm, as the name suggests, always makes the choice that seems to be the best at that moment.

    How do you decide which choice is optimal?
    Assume that you have an objective function that needs to be optimized (either maximized or minimized) at a given point.
    A Greedy algorithm makes greedy choices at each step to ensure that the objective function is optimized. The Greedy
    algorithm has only one shot to compute the optimal solution so that it never goes back and reverses the decision.

    The algorithm works in this way:
    coins = {1,2,5,10,20}, change = 26.
    starting from 20:
    if coin is greater than change, otherwise, move to the next one
    res = 26 - 20 = 6,
    maximum = 10,
    res (6) - maximum (10) >= 0 ? no
    maximum = 5;
    res (6) - maximum (5) >= 0 ? yes, update res.
    maximum = 2;
    res (1) - maximum (2) >= 0 ? no
    maximum = 1;
    res(1) - maximum (1) >= 0 ? yes, update res.

    Note: Most greedy algorithms are not correct. An example is described later in this article.

    coins = {1, 4, 6}
    change = 8
    starting from 6:
    res = 8 - 6, 2;
    maximum = 4;
    res(2) >= 4, no
    maximum = 1
    res(2) >= 1, yes, update res with 1
    res(1) >= 1, yes, updated res with 0.

    answer = {6, 1, 1}, is this the optimal solution? no
    a more optimal solution to this would be: {4,4}
*/

/*
    Another possible solution:
    change = 26
    m = {1, 2, 5, 10, 20}
    maximum (20)
    aux = change / maximum(20) = 1; change fits 1 time in 20
    change = change - ( 1 * maximum(20)) = 6
    number_coins = number_coins + 1;

    maximum (10)
    aux = change (6) / maximum (10) = 0, change (6) fits 0 times in 10
    change = change - (0 * maximum(10)) = 0
    number_coins = number_coins + 0;

    and so on...

    int coin_problem(int *coins, int qtd, int value) {
        int number_coins = 0;
        for(int i = qtd - 1; i >=0; i--) {
            int res = change / coins[i];
            change = change - (res * coins[i]);
            number_coins+=res;
        }
        return number_coins;
    }
*/

int coin_problem(int *coins, int qtd, int value) {
    // Starting from the maximum number to the minimum one
    int res = value;
    vector<int>c;
    for(int i = qtd - 1; i >= 0; i--) {
        while(coins[i] <= res) {
            res = res - coins[i];
            c.push_back(coins[i]);
        }
    }

    for(auto v : c) {
        cout << v << endl;
    }

    return (int)c.size();
}

int main()
{
    int coins[] = {1,2,5,10,20}; // coins available
    int change = 26;

    coin_problem(coins, 5, change);
    return 0;
}
