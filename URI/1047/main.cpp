#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    float h1,m1,h2,m2, horaAux, minAux;
    cin >> h1 >> m1 >> h2 >> m2;

    if(m1 <= m2) {
        minAux = m2 - m1;
        if(h1 < h2) {
            horaAux = h2 - h1;
        } else if (h1 == h2 && m1 < m2) {
            horaAux = 0;
        } else {
            horaAux = (h2 + 24) - h1;
        }
    } else {
        minAux = (m2 + 60) - m1;
        if(h1 < h2) {
            horaAux = (h2 - h1) - 1;
        } else {
            horaAux = ((h2 + 24) - h1) - 1;
        }
    }

    cout << "O JOGO DUROU " << horaAux << " HORA(S) E " << minAux << " MINUTO(S)\n";

    return 0;
}
