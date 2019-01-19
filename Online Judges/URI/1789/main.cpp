#include <iostream>

using namespace std;

int main()
{
    int quant, lesmas, maior;
    while(cin >> quant) {
        maior = 0;
        for ( int i = 0; i < quant; i++) {
            cin >> lesmas;
            if(lesmas > maior)
                maior = lesmas;
        }
        if(maior > 0 && maior < 10)
            cout << 1 << endl;
        else if (maior >= 10 && maior < 20)
            cout << 2 << endl;
        else if(maior >= 20)
            cout << 3 << endl;
    }
    return 0;
}
