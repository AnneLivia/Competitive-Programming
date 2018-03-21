#include <iostream>

using namespace std;

int main()
{
    int p,q,n;
    char c;
    cin >> n;
    cin >> p >> c >> q;
    if(c == '+') {
        if(p + q > n)
            cout << "OVERFLOW\n";
        else
            cout << "OK\n";
    } else {
        if(p * q > n)
            cout << "OVERFLOW\n";
        else
            cout << "OK\n";
    }
    return 0;
}
