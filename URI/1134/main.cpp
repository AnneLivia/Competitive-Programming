#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{

    int gas, dis, alc, opt;
    gas = dis = alc = 0;


    while(true)
    {
        do {
            cin >> opt;
        } while (opt < 1 || opt > 4);
        if(opt == 4)
            break;
        else if(opt == 1)
            alc +=1;
        else if(opt == 2)
            gas +=1;
        else if(opt == 3)
            dis +=1;
    }
    cout << "MUITO OBRIGADO\n";
    cout << "Alcool: " << alc << endl;
    cout << "Gasolina: " << gas << endl;
    cout << "Diesel: " << dis << endl;
    return 0;
}
