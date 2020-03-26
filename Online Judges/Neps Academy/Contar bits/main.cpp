#include <iostream>

using namespace std;

int main()
{
    long long unsigned int n, cont = 0;
    cin >> n;

    while(n) {
        if ((n & 1LL) != 0LL) {
            cont++;
        }
        n>>=1LL;
    }

    cout << cont << endl;
    return 0;
}
