#include <iostream>

using namespace std;

int main()
{
    long long unsigned int f, a, b, c;
    int t;
    cin >> t;
    while(t--) {
        cin >> f;
        if(f == 0)
            cout << "Fib(0) = " << 0 << endl;
        else if (f == 1)
            cout << "Fib(1) = " << 1 << endl;
        else {
            a = 1;
            b = 0;
            c = 1;
            for ( int i = 2; i < f; i++) {
                b = c;
                c = a;
                a = a + b;
            }
            cout << "Fib("<<f<<") = " << a << endl;
        }
    }
    return 0;
}
