#include <iostream>

using namespace std;

int main()
{
    int b[20];
    int nb, nd, bp, bc, de, flag;
    while(cin >> nb && cin >> nd && nb != 0 && nd != 0) {
        flag = 0;
        for ( int i = 0; i < nb; i++) {
            cin >> b[i];
        }

        for ( int i = 0; i < nd; i++) {
            cin >> bp >> bc >> de;
            b[bc - 1] += de;
            b[bp - 1] -= de;
        }
        for ( int i = 0; i < nb; i++) {
            if(b[i] < 0)
                flag = 1;
        }

        if(flag)
            cout << "N\n";
        else
            cout << "S\n";

    }
    return 0;
}
