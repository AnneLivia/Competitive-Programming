#include <iostream>

using namespace std;

int main()
{
    string s;
    int t, ss, qtd, ok, ind;
    cin >> t;
    while(t--) {
        qtd = ok = 0;
        cin >> ss;
        cin >> s;

        if(ss >= 11) {
            for (int i = 0; i < ss; i++) {
                qtd = ok = 0;
                for(int j = 0; j < ss; j++) {
                    if(s[j] == '8' && !ok) {
                        ok =  true;
                        ind = i;
                    }
                    if(ok)
                        qtd++;
                }

                if(qtd >= 11 || qtd <= 10) {
                    break;
                }
            }
        }

        if(qtd <= 10)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}
