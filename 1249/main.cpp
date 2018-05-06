#include <iostream>

using namespace std;

int main()
{
    string f, aux;
    int cont;
    while(getline(cin,f)) {
        aux = f;
        for(int i = 0; i < (int)f.size(); i++) {
            cont = 13;
            if(toupper(aux[i]) >= 'A' && toupper(aux[i]) <= 'Z') {
                while(cont--) {
                    aux[i]++;
                    if(toupper(aux[i]) > 'Z') {
                        aux[i] = 'a';
                    }
                }
            }
            if(f[i] == toupper(f[i]))
                aux[i] = toupper(aux[i]);

        }
        cout << aux << endl;
    }
    return 0;
}
