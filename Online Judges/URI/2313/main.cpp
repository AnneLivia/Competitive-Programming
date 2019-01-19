#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;

    if( a + b > c && abs(a - b) < c &&
        b + c > a && abs(b - c) < a &&
        a + c > b && abs(a - c) < b) {
        if(b == a && b == c)
            cout << "Valido-Equilatero\n";
        else if(a == b && a != c || a == c && a != b || c == b && c != a)
            cout << "Valido-Isoceles\n";
        else
            cout << "Valido-Escaleno\n";
        if (a >= b && a >= c) {
            if(pow(a,2.0) == (pow(b,2.0) + (pow(c,2.0))))
                cout << "Retangulo: S\n";
            else
                cout << "Retangulo: N\n";
        } else if (b >= a && b >= c) {
            if(pow(b,2.0) == (pow(a,2.0) + (pow(c,2.0))))
                cout << "Retangulo: S\n";
            else
                cout << "Retangulo: N\n";
        } else if (c >= a && c >= b) {
            if(pow(c,2.0) == (pow(b,2.0) + (pow(a,2.0))))
                cout << "Retangulo: S\n";
            else
                cout << "Retangulo: N\n";
        }
    } else {
        cout << "Invalido\n";
    }
    return 0;
}
