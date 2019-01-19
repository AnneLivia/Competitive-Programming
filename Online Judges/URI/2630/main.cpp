#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    int t, r, g, b, i = 1, v, minn, maxx;
    string conv;
    cin >> t;
    while(i <= t) {
        cin >> conv;
        cin >> r >> g >> b;
        cout << "Caso #" << i << ": ";

        if(conv.compare("eye") == 0) {
            v = 0.30*r+0.59*g+0.11*b;
            cout << v << endl;
        } else if (conv.compare("mean") == 0 ) {
            v = (r + g + b) / 3;
            cout << v << endl;
        } else if (conv.compare("max") == 0 ) {
            maxx = max(r,g);
            maxx = max(maxx,b);
            cout << maxx << endl;
        } else if (conv.compare("min") == 0 ) {
            minn = min(r,g);
            minn = min(minn,b);
            cout << minn << endl;
        }
        i++;
    }
    return 0;
}
