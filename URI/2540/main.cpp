#include <iostream>

using namespace std;

int main()
{
    int qtd, n, va, vc;

    while(cin >> qtd) {

        va = vc = 0;
        while(qtd--) {
            cin >> n;
            if(n)
                va++;
            else
                vc++;
        }

        if(va >= (vc + vc))
            cout << "impeachment\n";
        else
            cout << "acusacao arquivada\n";
    }


    return 0;
}
