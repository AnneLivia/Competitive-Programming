#include <cstring>
#include <cmath>
#include <iostream>
#include <cstdio>

using namespace std;

int contCalls;

int fib(int n) {
    contCalls++;
    if(n < 2)
        return n;
    return fib(n - 1) + fib(n - 2);
}
/*
int fib(int n, int memoization[]) {
    contCalls++;
    if(n <= 1) {
        return memoization[n];
    } else if (!memoization[n]) { // If the result is not at the array, insert it there
        memoization[n] = fib(n - 1, memoization) + fib(n - 2, memoization);
        contCalls+=2;
    }

    return memoization[n];
}
*/

int main()
{
    int memoization[40]; // Program goes from 1 to 39
    int nCalls[40];

    int n, t, res;
    scanf("%d",&t);
    while(t--) {
        contCalls = 0;

        //memset(memoization, 0, sizeof(int) * 40);

        //memoization[1] = 1;

        scanf("%d",&n);

        res = fib(n);

        printf("fib(%d) = %d calls = %d\n",n,(contCalls - 1), res);
    }


    return 0;
}
