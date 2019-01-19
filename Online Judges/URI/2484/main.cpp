#include <iostream>

using namespace std;

int main()
{
    string s, espa;
    while(cin >> s) {
        espa = "";
        int k = (int)s.size();
        while(k > 0) {
            cout << espa;
            for(int i = 0; i < k; i++) {
                if(i != 0)
                    cout << " ";
                cout << s[i];
            }
            cout << endl;
            k--;
            espa+=" ";
        }
        cout << endl;
    }
    return 0;
}
