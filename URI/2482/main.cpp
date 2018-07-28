#include <iostream>
#include <map>

using namespace std;

int main()
{
    int qtdI, qtdP;
    string s, idioma;
    map<string,string>m;
    cin >> qtdI;
    cin.ignore();
    while(qtdI--) {
        getline(cin,idioma);
        getline(cin,s);
        m.insert(make_pair(idioma,s));
    }

    cin >> qtdP;
    cin.ignore();
    while(qtdP--) {
        getline(cin,s);
        getline(cin,idioma);
        cout << s << "\n" << m.at(idioma) << endl << endl;
    }
    return 0;
}
