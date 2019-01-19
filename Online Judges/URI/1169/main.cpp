#include <iostream>

using namespace std;

int main()
{
    long long unsigned int cTestes,nCasas, cont;
    cin >> cTestes;
    while(cTestes--) {
        cont = 1;
        cin >> nCasas;
        if(nCasas == 64) {
            cout << 1537228672809129 << " kg\n";
            continue;
        } else if (nCasas >= 65) {
            cout << "Out of specification\n";
            continue;
        } else {
            while(nCasas--) {
                cont = cont + cont;
            }
        }
        cout << cont / 12 / 1000 << " kg" << endl;
    }
    return 0;
}
