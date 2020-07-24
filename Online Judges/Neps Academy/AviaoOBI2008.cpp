#include <iostream>

using namespace std;

int main() {
    int f, c, e, b, as = 0, fi, ok = 0;
    cin >> f >> c >> e >> b;
    fi = e;
    while(fi <= f) {
        if (as + c >= b) {
            int cont = 0, ste = as;
            while(ste <= b) {
                ste++;
                cont++;
            }
            cont-=2;
            cout << fi << " " << (char)(cont + 'A') << endl;
            ok = 1;
            break;
        }
        as+=c;
        fi++;
    }

    if (!ok) {
        cout << "PROXIMO VOO\n";
    }
    return 0;  
}
