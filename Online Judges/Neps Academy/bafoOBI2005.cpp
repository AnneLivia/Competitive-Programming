#include <iostream>

using namespace std;

int main() {
    int a, b, n, cont1, cont2, t = 1;

    while(cin >> n && n) {
        cont1 = cont2 = 0;
        while(n--) { 
            cin >> a >> b;
            cont1+=a;
            cont2+=b;
        }
        cout << "Teste " << t++ << endl;
        if (cont1 > cont2) {
            cout << "Aldo\n";
        } else {
            cout << "Beto\n";
        }
        cout << endl;
    }    
    return 0;  
}
