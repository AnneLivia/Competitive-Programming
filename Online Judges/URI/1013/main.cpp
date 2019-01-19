#include <iostream>
#include <stdio.h>
using namespace std;

int main() {

    int n1,n2,n3, maiorValor, abs2;
    cin >> n1 >> n2 >> n3;
    abs2 = n1 - n2;
    if(abs2 < 0)
        abs2 = abs2 * -1;

    maiorValor = (n1+n2+abs2) / 2;
    abs2 = maiorValor - n3;
    if(abs2 < 0)
        abs2 = abs2 * -1;
    maiorValor = (maiorValor + n3 + abs2) / 2;
    cout << maiorValor << " eh o maior\n";
    return 0;
}
