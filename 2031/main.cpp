#include <iostream>
#include <string>

using namespace std;

string allower(string s) {
   for(int i = 0; i < (int)s.size(); i++) {
        s[i] = tolower(s[i]);
   }
   return s;
}
int main()
{
    int q,a1,pe1,pa1, a2, pe2, pa2;
    string c1,c2;
    cin >> q;
    while(q--) {
        a1 = pe1 = pa1 = a2 = pe2 = pa2 = 0;
        cin >> c1 >> c2;
        c1 = allower(c1);
        c2 = allower(c2);
        if(c1.compare("ataque") == 0)
            a1 = 1;
        else if (c1.compare("pedra") == 0)
            pe1 = 1;
        else if (c1.compare("papel") == 0)
            pa1 = 1;

        if(c2.compare("ataque") == 0)
            a2 = 1;
        else if (c2.compare("pedra") == 0)
            pe2 = 1;
        else if (c2.compare("papel") == 0)
            pa2 = 1;

        if(a1 && pe2)
            cout << "Jogador 1 venceu\n";
        else if (a2 && pe1)
            cout << "Jogador 2 venceu\n";
        else if (pe1 && pa2)
            cout << "Jogador 1 venceu\n";
        else if (pe2 && pa1)
            cout << "Jogador 2 venceu\n";
        else if (a1 && pa2)
            cout << "Jogador 1 venceu\n";
        else if (a2 && pa1)
            cout << "Jogador 2 venceu\n";
        else if (pa1 && pa2)
            cout << "Ambos venceram\n";
        else if (pe1 && pe2)
            cout << "Sem ganhador\n";
        else if (a1 && a2)
            cout << "Aniquilacao mutua\n";
    }
    return 0;
}
