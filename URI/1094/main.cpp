#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{

    int nTestes, quantia, total = 0;
    float totEach[3] = {0};
    char tipo;
    cin >> nTestes;


    for (int i = 1; i <= nTestes; i++)
    {
        do {
            cin >> quantia;
        } while (quantia < 1 || quantia > 15);
        total += quantia;
        cin >> tipo;
        if(tipo == 'C' || tipo == 'c') {
            totEach[0] +=quantia;
        } else if ( tipo == 'R' || tipo == 'r') {
            totEach[1] +=quantia;
        } else if (tipo == 's' || tipo == 'S') {
            totEach[2] +=quantia;
        }
    }

    cout << "Total: " << total << " cobaias" << endl;
    cout << "Total de coelhos: " << totEach[0] << endl;
    cout << "Total de ratos: " << totEach[1] << endl;
    cout << "Total de sapos: " << totEach[2] << endl;
    printf("Percentual de coelhos: %.2f %%\n"
           "Percentual de ratos: %.2f %%\n"
           "Percentual de sapos: %.2f %%\n",totEach[0] * 100/ total,
                                         totEach[1] * 100 / total,
                                         totEach[2] * 100 / total);

    return 0;
}
