#include <iostream>

using namespace std;

int main()
{
    double o, b, i;
    cin >> o >> b >> i;
    if(o < b && o < i)
        cout << "Otavio\n";
    else if (b < o && b < i)
        cout << "Bruno\n";
    else if (i < o && i < b)
        cout << "Ian\n";
    else
        cout << "Empate\n";
    return 0;
}
