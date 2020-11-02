#include <iostream>
#include <vector>

using namespace std;

int main() {
    int v, p, inc, pa;
    cin >> v >> p;
    inc = v % p;
    pa = v / p;
    while(p--) {
        if (inc) {
            cout << pa + 1 << endl;
            inc--;
        } else
            cout << pa << endl;
        
    }
    return 0;
}