#include <iostream>

using namespace std;

int main()
{
    string name, lastname, aux;
    int t, ja, cont;
    cin >> t;
    cin.ignore();
    while(t--) {
        aux = ""; ja = 1, cont = 0;
        getline(cin,name);
        getline(cin,lastname);

        for ( int i = 0, j = 0; i < (int)name.size(), j < (int)lastname.size();) {
            if(ja) {
                aux+=name[i++];
                cont++;
                if(cont == 2) {
                    ja = 0;
                    cont = 0;
                }
            } else {
                aux+=lastname[j++];
                cont++;
                if(cont == 2) {
                    ja = 1;
                    cont = 0;
                }
            }
        }
        cout << aux << endl;
    }
    return 0;
}
