#include <iostream>

using namespace std;

int main()
{
    int p, d1, d2;
    cin >> p >> d1 >> d2;
    if((d1 + d2) % 2 == 0) {
        if(p == 0)
            cout << "0\n";
        else
            cout << "1\n";
    } else {
        if(p == 0)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
