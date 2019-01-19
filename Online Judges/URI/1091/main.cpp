#include <iostream>

using namespace std;

int main()
{
    int t, c1, c2, d1, d2;
    while(cin >> t && t) {
        cin >> d1 >> d2;
        while(t--) {
            cin >> c1 >> c2;
            if(c1 == d1 || c2 == d2) {
                cout << "divisa" << endl;
            } else {
                if(c2 > d2) {
                    if(c1 < d1) {
                        cout << "NO\n";
                    } else {
                        cout << "NE\n";
                    }
                } else {
                    if(c1 < d1) {
                        cout << "SO\n";
                    } else {
                        cout << "SE\n";
                    }
                }
            }
        }
    }
    return 0;
}
