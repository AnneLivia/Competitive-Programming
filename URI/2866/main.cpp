#include <iostream>

using namespace std;

int main()
{
    int qtd;
    string s, aux;
    cin >> qtd;
    while(qtd--) {
        cin >> s;
        aux = "";
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == tolower(s[i]))
                aux+=s[i];
        }
        cout << aux << endl;
    }
    return 0;
}
