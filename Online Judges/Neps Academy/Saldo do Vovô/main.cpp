#include <iostream>

using namespace std;

int main()
{
    int m, n, saldo, q;

    cin >> n >> saldo;

    m = saldo;
    while(n--) {
        cin >> q;
        saldo+=q;
        if(saldo < m)
            m = saldo;
    }
    cout << m << endl;
    return 0;
}
