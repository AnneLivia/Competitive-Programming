#include <iostream>

using namespace std;

int main() {
    int c, f, pc = 0, pf = 0;

    for (int i = 0; i < 3; i++)
    {
        cin >> c;
        if (i == 0) {
            pc = c * 3;
        } else if (i == 1) {
            pc +=c;
        } 
    }

     for (int i = 0; i < 3; i++)
    {
        cin >> f;
        if (i == 0) {
            pf = f * 3;
        } else if (i == 1) {
            pf +=f;
        } 
    }
        
    if (pc > pf) {
        cout << "C\n";
    } else if (pc == pf) {
        if (c > f) {
            cout << "C\n";
        } else if (f > c) {
            cout << "F\n";
        } else if (c == f) {
            cout << "=\n";
        }
    } else {
        cout << "F\n"; 
    }
    return 0;  
}
