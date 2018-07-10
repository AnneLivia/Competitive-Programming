#include <iostream>

using namespace std;

int main()
{
    bool p = true;
    string s,r = "";
    getline(cin,s);
    s+=' ';
    for(int i = 0; i < (int)s.size(); i++) {
        if( i != 0 && i < (int)s.size() - 1 && s[i] == ' ')
            r+=' ';

        if(!p) {
            r+=s[i];
            p = true;
        } else if (s[i] != ' ') {
            p = false;
        }
    }

    cout << r << endl;
    return 0;
}
