#include <iostream>

using namespace std;

int main()
{
    string cpf;
    int b1, b2;

    while(cin >> cpf) {
        b1 = b2 = 0;
        for(int i = 0; i < (int)cpf.size(); i++) {
            b1+= ((i + 1) * (cpf[i] - '0'));
            b2+= ((9 - i) * (cpf[i] - '0'));
        }
        b1 = b1 % 11;
        b2 = b2 % 11;
        if(b1 == 10)
            b1 = 0;
        if(b2 == 10)
            b2 = 0;
        for(int i = 0; i < (int)cpf.size(); i++) {
            if(i == 3 || i == 6)
             cout << ".";
            cout << cpf[i];
        }
        cout << "-" << b1 << b2 << endl;
    }
    return 0;
}
