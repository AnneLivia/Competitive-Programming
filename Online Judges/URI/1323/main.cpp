#include <iostream>
#include <cstring>

using namespace std;

int memo[101];

int feynman(const int& n) {
    if(memo[n] != 0)
        return memo[n];

    if (n == 1)
        memo[n] = 1;
    else
        memo[n] = (n * n) + feynman(n - 1);

    return memo[n];
}

int main()
{
    memset(memo, 0, sizeof(memo[0]) * 101);

    int n;
    while(cin >> n && n) {
        cout << feynman(n) << endl;
    }

    return 0;
}
