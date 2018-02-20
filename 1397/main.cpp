#include <iostream>

using namespace std;

int main()
{
    int qtd, soma1, soma2, num1,num2;
    while(true) {
        cin >> qtd;
        soma1 = soma2 = 0;
        if(!qtd)
            break;
        while(qtd--) {
            cin >> num1 >> num2;
            if(num1 > num2)
                soma1++;
            else if (num1 < num2)
                soma2++;
        }
        cout << soma1 << " " << soma2 << endl;
    }
    return 0;
}
