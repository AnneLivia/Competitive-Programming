#include <iostream>

using namespace std;

int main()
{
    int n1, t, n2;
    char l, aux;
    cin >> t;
    while(t--) {
        cin >> n1 >> l >> n2;
        aux = toupper(l);
        int aA = aux;
        int aL = l;

        if(n1 == n2) {
            cout << n1 * n2 << endl;
        } else if (aL == aA) {
            cout << n2 - n1 << endl;
        } else {
            cout << n1 + n2 << endl;
        }
    }
    return 0;
}
