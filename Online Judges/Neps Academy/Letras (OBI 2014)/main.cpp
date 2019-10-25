#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    char s;
    string t,x;
    float d = 0, total = 0;
    cin >> s;
    cin.ignore();
    getline(cin , t);
    x = "";
    t.push_back(' ');
    for (int i = 0; i < (int)t.size(); i++) {
        if(t[i] !=  ' ') {
            x+=t[i];
        } else {
            total++;
            if(find(x.begin(), x.end(), s) != x.end()) {
                d++;
            }
            x = "";
        }
    }
    cout.precision(1);
    cout.setf(ios::fixed);
    cout << d *  100 / total << endl;
    return 0;
}
