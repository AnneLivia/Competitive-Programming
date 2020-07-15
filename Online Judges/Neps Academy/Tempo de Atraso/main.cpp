#include <iostream>

using namespace std;

int main()
{
    int h1, m1, h2, m2;

    cin >> h1 >> m1 >> h2 >> m2;

    int tt = (((h2 - h1) * 60) + (m2 - m1)) - 45;
    if (tt >= 0)
        cout << "Sucesso\n";
    else
        cout << "Atrasado " << abs(tt) << "\n";

    return 0;
}
