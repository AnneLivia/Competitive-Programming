#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int cont;
    string str, vogais;
    while(cin >> vogais) {
        cin.ignore();
        if(!getline(cin,str))
            break;
        cont = 0;
        for ( int i = 0; i < (int)str.size(); i++) {
            if(find(vogais.begin(),vogais.end(),str[i]) != vogais.end())
                cont++;
        }
        cout << cont << endl;
    }
    return 0;
}
