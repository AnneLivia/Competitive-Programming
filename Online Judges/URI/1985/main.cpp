#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int qtd, valueBuy, qtdBuy;
    float price = 0.0;
    cin >> qtd;

    while(qtd--) {
        cin >> valueBuy >> qtdBuy;
        switch(valueBuy) {
        case 1001 : price +=1.50 * qtdBuy; break;
        case 1002 : price +=2.50 * qtdBuy; break;
        case 1003 : price +=3.50 * qtdBuy; break;
        case 1004 : price +=4.50 * qtdBuy; break;
        case 1005 : price +=5.50 * qtdBuy; break;
        }
    }
    printf("%.2f\n",price);
    return 0;
}
