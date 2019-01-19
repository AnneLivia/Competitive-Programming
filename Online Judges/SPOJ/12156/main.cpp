#include <iostream>

using namespace std;

int main()
{
    string s;
    int t;
    cin >> t;
    while(t--) {
        cin >> s;
        for(int i = 0; i < ((int)s.size()) / 2; i+=2)
            cout << s[i];
        cout << endl;
    }
    return 0;
}
