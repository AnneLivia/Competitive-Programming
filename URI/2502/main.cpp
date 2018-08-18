#include <iostream>
#include <algorithm>

using namespace std;
void tolowers(string& s) {
    for(int i = 0; i < (int)s.size(); i++)
        s[i] = tolower(s[i]);
}

int posfind(char c, string w) {
    for(int i = 0; i < (int)w.size(); i++) {
        if(c == w[i])
            return i;
    }
    return -1;
}

bool symbol(char c) {
    if(c == '.' || c == '!' || c == '?' || c == ',' || c == ';' ||
       c == ':' || c == '(' || c == ')')
        return true;
    return false;
}

int main()
{
    int c, n, p;
    string c1, c2, s;
    while(cin >> c >> n) {
        cin.ignore();
        getline(cin,c1);
        getline(cin,c2);

        tolowers(c1);
        tolowers(c2);

        while(n--) {
            getline(cin,s);

            for(int i = 0; i < (int)s.size(); i++) {
                p = posfind(tolower(s[i]),c1);
                if(p != -1) {
                    if(s[i] == toupper(s[i]) && !(s[i] >= '0' && s[i] <= '9') && !isspace(s[i]) && !symbol(s[i]) && isalpha(s[i]))
                        s[i] = toupper(c2[p]);
                    else
                        s[i] = c2[p];
                } else {
                    p = posfind(tolower(s[i]),c2);
                    if(p != -1) {
                        if(s[i] == toupper(s[i]) && s[i] == toupper(s[i]) && !(s[i] >= '0' && s[i] <= '9') && !isspace(s[i]) && !symbol(s[i]) && isalpha(s[i]))
                            s[i] = toupper(c1[p]);
                        else
                            s[i] = c1[p];
                    }
                }
            }
            cout << s << endl;
        }
        cout << endl;
    }
    return 0;
}
