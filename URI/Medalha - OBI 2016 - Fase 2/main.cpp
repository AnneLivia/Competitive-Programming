#include <iostream>

using namespace std;

int main()
{
    int swimmer1, swimmer2, swimmer3;
    cin >> swimmer1 >> swimmer2 >> swimmer3;
    if(swimmer1 < swimmer2 && swimmer1 < swimmer3)
        cout << "1\n";
    if(swimmer2 < swimmer1 && swimmer2 < swimmer3)
        cout << "2\n";
    if(swimmer3 < swimmer2 && swimmer3 < swimmer1)
        cout << "3\n";
    if(swimmer1 > swimmer2 && swimmer1 < swimmer3)
        cout << "1\n";
    if(swimmer1 > swimmer3 && swimmer1 < swimmer2)
        cout << "1\n";
    if(swimmer2 > swimmer1 && swimmer2 < swimmer3)
        cout << "2\n";
    if(swimmer2 > swimmer3 && swimmer2 < swimmer1)
        cout << "2\n";
    if(swimmer3 > swimmer2 && swimmer3 < swimmer1)
        cout << "3\n";
    if(swimmer3 > swimmer1 && swimmer3 < swimmer2)
        cout << "3\n";
    if(swimmer1 > swimmer2 && swimmer1 > swimmer3)
        cout << "1\n";
    if(swimmer2 > swimmer1 && swimmer2 > swimmer3)
        cout << "2\n";
    if(swimmer3 > swimmer2 && swimmer3 > swimmer1)
        cout << "3\n";
    return 0;
}
