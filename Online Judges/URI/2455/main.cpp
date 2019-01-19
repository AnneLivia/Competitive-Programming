#include <iostream>

using namespace std;

int main()
{
    int p1, c1, p2, c2, peso1, peso2;
    cin >> p1 >> c1 >> p2 >> c2;

    peso1 = p1 * c1;
    peso2 = p2 * c2;

    if(peso1 == peso2)
        cout << "0\n";
    else {
        if(peso1 > peso2)
            cout << "-1\n";
        else
            cout << "1\n";
    }
    return 0;
}
