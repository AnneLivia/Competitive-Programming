#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{

    float nota, media = 0;
    int conTot = 0;
    while(true)
    {
        cin >> nota;
        if(nota >= 0 && nota <= 10)
        {
            media +=nota;
            conTot +=1;
            if(conTot == 2)
                break;
        } else {
            cout << "nota invalida\n";
        }
    }
    media = media / conTot;
    printf("media = %.2f\n",media);

    return 0;
}
