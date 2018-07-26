#include <iostream>

using namespace std;

int main()
{
    int n, tam, cont, j;
    string s1, s2;
    cin >> n;
    while(n--) {
        cin >> s1 >> s2;
        cont = 0;
        if(s2.size() > s1.size())
            cout << "nao encaixa\n";
        else {
            tam = (int)s2.size();
            j = 0;
            for(int i = (int)s2.size() - 1; i >= 0; i--) {
                if(s2[i] == s1[((int)s1.size() - 1) - j])
                    cont++;
                j++;
            }
            if(cont == (int)s2.size())
                cout << "encaixa\n";
            else
                cout << "nao encaixa\n";
        }
    }
    return 0;
}
