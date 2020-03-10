#include <iostream>

using namespace std;

int main() {
    long long int n, va, pr = 0, cont = 0;
    cin >> n;
    while(n--) {
        cin >> va;
        if (va < pr) {
            cont+=pr-va;
            va = va + (pr - va);
        }
        pr = va;
    }
    cout << cont << endl;
    return 0;
}