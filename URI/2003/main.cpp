#include <iostream>

using namespace std;

int main()
{
    int h, m, auxh, auxm;
    char c;

    while(cin >> h >> c >> m) {
        auxh = h;
        auxm = m;

        auxm+=60;
        if(auxm >= 60) {
            auxh+=1;
            auxm-=60;
        }

        auxh = auxh - 8;
        if(auxh < 0) {
            cout << "Atraso maximo: " << 0 << endl;
        } else {
            auxh*=60;
            auxh+=auxm;
            cout << "Atraso maximo: " << auxh << endl;
        }
    }
    return 0;
}
