#include <iostream>

using namespace std;

int main()
{
    int cv, ce, cs, fv, fe, fs, pc, pf;
    pc = pf = 0;
    cin >> cv >> ce >> cs >> fv >> fe >> fs;
    pc = (cv * 3) + (ce * 1);
    pf = (fv * 3) + (fe * 1);

    if(pc == pf) {
        if(cs > fs)
            cout << "C\n";
        else if (fs > cs)
            cout << "F\n";
        else
            cout << "=\n";
    } else if (pc > pf) {
        cout << "C\n";
    } else {
        cout << "F\n";
    }
    return 0;
}
