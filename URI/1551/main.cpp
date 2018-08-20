#include <iostream>
#include <set>

using namespace std;

int main()
{
    int t, cont;
    string s;
    set<char>se;
    cin >> t;
    cin.ignore();
    while(t--) {
        cont = 0;
        se.clear();
        getline(cin,s);
        for(int i = 0; i < (int)s.size(); i++) {
            if(s[i] != ',' && s[i] != ' ')
                se.insert(s[i]);
        }
        if((int)se.size() == 26)
            cout << "frase completa\n";
        else if ((int)se.size() >= 13)
            cout << "frase quase completa\n";
        else
            cout << "frase mal elaborada\n";
    }
    return 0;
}
