#include <iostream>

using namespace std;

int main()
{
    string s, r = "";
    int p = 0;
    getline(cin, s);
    for (int i = 1; i < (int)s.size(); i++) {
        if (tolower(s[i - 1]) == 'p') {
            r+=s[i];
            if (tolower(s[i]) == 'p')
                s[i] = 'o';
        } else if (s[i] == ' ')
            r+=s[i];
    }
    cout << r << endl;
    return 0;
}
