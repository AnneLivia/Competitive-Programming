#include <iostream>
#include <set>
#include <cstdio>
#include <cstring>

using namespace std;
string upper(string a) {
    for(int i = 0; i < a.length(); i++) {
        a[i] = toupper(a[i]);
    }
    return a;
}

string check(const string& a, const set<string>& b) {
    string copyWord;
    set<string>::iterator i;
    for(i = b.begin(); i != b.end(); i++) {
        copyWord = upper(*i);
        if(strcmp(a.c_str(),copyWord.c_str()) == 0) {
            break;
        }
    }
    copyWord = *i;
    return copyWord;
}

int main()
{
    set<string>nomes, nomesChanged;
    string nome;
    bool camein = false;

    while(getline(cin,nome)) {
        camein = true;
        nomesChanged.insert(nome);
        nome = upper(nome);
        nomes.insert(nome);
    }
    if(camein) {
        set<string>::iterator lastName = --nomes.end();
        nome = check(*lastName,nomesChanged);
        cout << nome << endl;
    }
    return 0;
}
