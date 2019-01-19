#include <iostream>
#include <map>

using namespace std;

int main()
{
    int nLetter;
    string letter;
    map<string,char>alph;
    alph["."] = 'a';
    alph[".."] = 'b';
    alph["..."] = 'c';
    alph[". ."] = 'd';
    alph[".. .."] = 'e';
    alph["... ..."] = 'f';
    alph[". . ."] = 'g';
    alph[".. .. .."] = 'h';
    alph["... ... ..."] = 'i';
    alph[". . . ."] = 'j';
    alph[".. .. .. .."] = 'k';
    alph["... ... ... ..."] = 'l';
    alph[". . . . ."] = 'm';
    alph[".. .. .. .. .."] = 'n';
    alph["... ... ... ... ..."] = 'o';
    alph[". . . . . ."] = 'p';
    alph[".. .. .. .. .. .."] = 'q';
    alph["... ... ... ... ... ..."] = 'r';
    alph[". . . . . . ."] = 's';
    alph[".. .. .. .. .. .. .."] = 't';
    alph["... ... ... ... ... ... ..."] = 'u';
    alph[". . . . . . . ."] = 'v';
    alph[".. .. .. .. .. .. .. .."] = 'w';
    alph["... ... ... ... ... ... ... ..."] = 'x';
    alph[". . . . . . . . ."] = 'y';
    alph[".. .. .. .. .. .. .. .. .."] = 'z';

    while(cin >> nLetter) {
        cin.ignore();
        while(nLetter--) {
            getline(cin,letter);
            cout << alph[letter] << endl;
        }
    }

    return 0;
}
