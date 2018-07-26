#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, cont, ok, qtdnome;
    string nome, raca, especie, aux, e;

    while(cin >> n) {
        cont = 0;
        cin.ignore();
        while(n--) {
            ok = qtdnome = 0;
            getline(cin,especie);
            getline(cin,raca);
            getline(cin,nome);
            getline(cin,e);
            if(especie.compare("cachorro") == 0) {
                aux = "";
                nome+=" ";
                for ( int i = 0; i < (int)nome.size(); i++) {
                    if(nome[i] != ' ') {
                        aux+=nome[i];
                    } else {
                        qtdnome++;
                        if(aux[0] == raca[0]) {
                            ok = true;
                        }
                        aux = "";
                    }
                }
            }
            //cout << qtdnome << endl;
            if(ok && qtdnome >= 2)
                cont++;
        }
        cout << cont << endl;
    }
    return 0;
}
