#include <iostream>

using namespace std;

int main()
{
    string s;
    int tur = 0, jip = 0, qtd;
    while(cin >> s && s != "ABEND") {
        cin >> qtd;

        if(s == "SALIDA") {
            jip+=1;
            tur+=qtd;
        } else {
            jip--;
            tur-=qtd;
        }
    }

    cout << tur << endl << jip << endl;
    return 0;
}
