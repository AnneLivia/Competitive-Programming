#include <iostream>

using namespace std;

int main()
{
    string s, aux;
    float sum = 0.0;
    int qtd = 0, i;
    cin >> s;

    i = 0;
    aux = "";

    while(s[i] != '\0') {
        aux+=s[i];
        if(stoi(aux) >= 10) {
            if(aux != "10") {
                i--;
                aux.pop_back();
            }
            sum+=stoi(aux);
            aux = "";
            qtd++;
        }
        i++;
    }
    if(aux != "" && aux != "0") {
        sum+=stoi(aux);
        qtd++;
    }
    cout.precision(2);
    cout.setf(ios::fixed);
    cout << sum / qtd << endl;
    return 0;
}
