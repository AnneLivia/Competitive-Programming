#include <iostream>

using namespace std;

int main()
{
    int t, tam;
    string aux, s;
    cin >> t;
    cin.ignore();
    while(t--) {
        aux = "";
        getline(cin,s);
        tam = ((int)s.size()) / 2;
        for (int i = tam - 1; i >= 0; i--) {
            aux+=s[i];
        }

        for (int i = (int)s.size() - 1; i >= tam; i--) {
            aux+=s[i];
        }

        cout << aux << endl;

    }
    return 0;
}
