#include <iostream>

using namespace std;

int main()
{
    int t, a, b, suma,sumb, teste = 1;
    while(cin >> t && t != 0) {
        suma = sumb = 0;
        while(t--) {
            cin >> a >> b;
            suma+=a; sumb+=b;
        }
        cout << "Teste " << teste++ << endl;
        if(suma > sumb) {
            cout << "Aldo\n\n";
        } else {
            cout << "Beto\n\n";
        }
    }
    return 0;
}
