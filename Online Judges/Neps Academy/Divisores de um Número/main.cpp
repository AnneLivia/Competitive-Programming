#include <iostream>

using namespace std;

int main()
{
    int n, qtddiv = 0, sumdiv = 0, v[1001];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            v[qtddiv++] = i;
            sumdiv+=i;
        }
    }
    cout << qtddiv << " divisor(es): ";
    for (int i = 0; i < qtddiv; i++) {
        if (i != 0)
            cout << " ";
        cout << v[i];
    }
    cout << "\nSoma de divisores = " << sumdiv << endl;
    if (qtddiv == 2) {
        cout << "Primo\n";
    } else {
        cout << "Nao primo\n";
    }
    return 0;
}
