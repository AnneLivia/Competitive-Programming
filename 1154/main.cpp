#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{

    int idade, soma = 0, tot = 0;

    cin >> idade;
    while(idade > 0) {
        soma = idade + soma;
        tot++;
        cin >> idade;
    }

    printf("%.2f\n",(float)soma/tot);
    return 0;
}
