#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    string a, b, c;
    getline(cin,a);
    getline(cin,b);
    getline(cin,c);
    cout << a << b << c << endl;
    cout << b << c << a << endl;
    cout << c << a << b << endl;
    for (int i = 0; i < 10 && i < (int)a.size(); i++)
        cout << a[i];
    for (int i = 0; i < 10 && i < (int)b.size(); i++)
        cout << b[i];
    for (int i = 0; i < 10 && i < (int)c.size(); i++)
        cout << c[i];
    cout << endl;
    return 0;
}
