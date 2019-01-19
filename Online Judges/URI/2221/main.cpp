#include <iostream>

using namespace std;

int main()
{
    int nTimes,bonus, attack[2],defense[2],level[2];
    float valorGolpe1,valorGolpe2;
    cin >> nTimes;
    while(nTimes--) {
        cin >> bonus;
        cin >> attack[0] >> defense[0] >> level[0]; // Dabriel
        cin >> attack[1] >> defense[1] >> level[1]; // Guarte
        valorGolpe1 = ( attack[0] + defense[0] ) / 2.0;
        valorGolpe2 = ( attack[1] + defense[1] ) / 2.0;
        if(level[0] % 2 == 0)
            valorGolpe1 +=bonus;
        if(level[1] % 2 == 0)
            valorGolpe2 +=bonus;
        if(valorGolpe1 > valorGolpe2)
            cout << "Dabriel" << endl;
        else if (valorGolpe1 < valorGolpe2)
            cout << "Guarte" << endl;
        else
            cout << "Empate" << endl;
    }
    return 0;
}
