#include <iostream>

using namespace std;

int main()
{
    int dias, saldoM = 999999999, saldo, n;
    cin >> dias >> saldo;
    while(dias--) {
        cin >> n;
        saldo+= n;
        if(saldo < saldoM)
            saldoM = saldo;
    }
    cout << saldoM << endl;
    return 0;
}
