#include <iostream>

using namespace std;

int main()
{
    string s, yeah;
    cin >> s;
    for ( int i = 0; i < (int)s.size(); i++) {
        s[i] = tolower(s[i]);
    }

    size_t pos = s.find("zelda");
    if(pos != string::npos) {
        cout << "Link Bolado\n";
    } else {
        cout << "Link Tranquilo\n";
    }
    return 0;
}
