#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    string s;
    double x;

    cin >> s;

    x = stod(s);

    if(s[0] != '-')
        cout << "+";
    printf("%.4E\n",x);
    return 0;
}
