#include <iostream>

using namespace std;

int main()
{
    int compr, cont;
    char bloco;
    cont = 0;
    cin >> compr;
    while(compr--) {
        cin >> bloco;
        if(bloco == 'A')
            cont+=1;
        else if(bloco == 'P')
            cont+=2;
        else if(bloco == 'C')
            cont+=2;
    }
    cout << cont << endl;
    return 0;
}
