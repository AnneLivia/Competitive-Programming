#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int l, aux, cont = 1; // One piece at first
    cin >> l;
    aux = l;
    while(aux >= 2) {
        aux = aux/2;
        cont*=4; // generating 4 pieces
    }
    cout << cont << endl;
    return 0;
}
