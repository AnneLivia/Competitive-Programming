#include <iostream>

using namespace std;

int main()
{
    string s;
    string n;

    while(getline(cin,s)) {
        n = "";
        for(int i = 0; i < (int)s.size(); i++) {
            if(isdigit(s[i]) || toupper(s[i]) == 'O' || s[i] == 'l') {
                if(s[i] == 'l') {
                    n+='1';
                } else if (tolower(s[i]) == 'o') {
                    n+='0';
                } else {
                    n+=s[i];
                }
            } else if (s[i] != ',' && s[i] != ' ' && s[i] != 'l' && tolower(s[i]) != 'o') {
                n = "";
                break;
            }
        }
        if(n != "") {
            try {
                if(stoi(n) <= 2147483647)
                    cout << stoi(n) << endl;
                else
                    throw;
            } catch(...) {
                cout << "error" << endl;
            }
        } else {
            cout << "error\n";
        }
    }
    return 0;
}
