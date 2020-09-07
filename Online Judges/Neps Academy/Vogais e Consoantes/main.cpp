#include <iostream>

using namespace std;

int main()
{
    string vo="", co = "", st;
    cin >> st;
    for(int i = 0; i < st.size(); i++) {
        if (st[i] == 'a' || st[i] == 'e' || st[i] == 'i' || st[i] == 'o' || st[i] == 'u') {
            vo+=st[i];
        } else {
            co+=st[i];
        }
    }
    cout << "Vogais: " << vo << endl;
    cout << "Consoantes: " << co << endl;
    return 0;
}
