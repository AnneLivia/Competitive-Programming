#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
long long unsigned int fat(long long unsigned int x) {
    if(x == 0)
        return 1;
    else
        return x * fat(x - 1);
}
int main()
{
    long long unsigned int m,n,sum;
    while(cin >> m >> n) {
        sum = fat(m) + fat(n);
        cout << sum << endl;
    }
    return 0;
}
