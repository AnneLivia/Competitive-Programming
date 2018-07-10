#include <iostream>
#include <string>

using namespace std;

int main()
{
    string n1, n2, strSoma;
    int soma;
    while(true) {
        cin >> n1 >> n2;
        if(n1 == "0" && n2 == "0")
            break;
        soma = stoi(n1) + stoi(n2);
        strSoma = to_string(soma);
        size_t found = strSoma.find('0');
        while(found != string::npos) {
            strSoma.erase(strSoma.begin() + found);
            found = strSoma.find('0');
        }
        cout << strSoma << endl;
    }
    return 0;
}
