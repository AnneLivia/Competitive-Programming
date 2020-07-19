#include <iostream>

using namespace std;

int main()
{
    int n1, n2;
    float m;
    cin >> n1 >> n2;

    m = (2 * n1 + 3 * n2) / (5.0);

    if (m >= 7)
        cout << "Aprovado\n";
    else if (m >= 3) {
        cout << "Final\n";
    } else {
        cout << "Reprovado\n";
    }
    return 0;
}
