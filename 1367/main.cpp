#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main()
{

    string senha;
    int num, maius, minusc, espaorsimb;
    while(getline(cin,senha)) {
        num = maius = minusc = espaorsimb = 0;
        for(int i = 0; i < (int)senha.size(); i++) {
            if(senha[i] == toupper(senha[i]) && isalpha(senha[i])) {
                maius+=1;
            } else if(senha[i] == tolower(senha[i]) && isalpha(senha[i])) {
                minusc+=1;
            } else if((senha[i] - '0') >= 0 && (senha[i] - '0') <= 9) {
                num+=1;
            } else {
                espaorsimb+=1;
            }

        }

        if(maius >= 1 && minusc >= 1 && num >= 1 && espaorsimb == 0 && (int)senha.size() >= 6 && (int)senha.size() <= 32)
            cout << "Senha valida.\n";
        else
            cout << "Senha invalida.\n";
    }
    return 0;
}
