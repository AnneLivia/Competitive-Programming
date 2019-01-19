#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int memo[100001];

int resultTwo(int n) {
    if(n < 0)
        return 0;

    if(memo[n] != 0)
        return memo[n];

    if(n == 1)
        memo[n] = 1;
    else {
        int ok = false;
        for (int i = 0; i <= sqrt(n); i++) {
            for(int j = 0; j <= sqrt(n); j++) {
                if((i * i) + (j * j) == n) {
                    memo[n] = (i * i) + (j * j);
                    ok = true;
                    break;
                }
            }
            if(ok)
                break;
        }
    }

    return memo[n];
}

int main()
{
    int n, sum = -1;

    memset(memo, 0, sizeof(memo));

    while(cin >> n) {
        if(resultTwo(n) || n == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
