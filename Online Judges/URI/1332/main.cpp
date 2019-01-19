#include <iostream>

using namespace std;

int main()
{
    int t;
    string s;
    cin >> t;
    while(t--) {
        cin >> s;
        if((int)s.size() == 3) {
            if(s[0] == 'o' && s[1] == 'n' || s[0] == 'o' && s[2] == 'e' || s[1] == 'n' && s[2] == 'e') {
                cout << 1 << endl;
            } else {
                cout << 2 << endl;
            }
        } else {
            cout << 3 << endl;
        }
    }
    return 0;
}
