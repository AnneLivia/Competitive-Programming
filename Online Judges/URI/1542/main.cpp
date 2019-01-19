#include <iostream>

using namespace std;

int main()
{
    int q, d, p, r;
    while(cin >> q && q != 0) {
        cin >> d >> p;
        r = (q * d * p) / (p - q);
        if(r == 1)
            cout << r << " pagina" << endl;
        else
            cout << r << " paginas" << endl;
    }
    return 0;
}
