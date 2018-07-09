#include <iostream>

using namespace std;

int main()
{
    string k;
    int n, k1, k2, ja;
    cin >> n;
    while(n--) {
        k1 = k2 = 0; ja = 1;
        cin >> k;
        k+=" ";
        for ( int i = 0; i < (int)k.size(); i++) {
            if(k[i] == 'a' && ja == 1) {
                k1++;
            } else if (k1 != 0) {
                ja = 2;
            }

            if(k[i] == 'a' && ja == 2) {
                k2++;
            }
        }
        cout << "k";
        for ( int i = 1; i <= k1*k2; i++) {
            cout << "a";
    }
    cout << endl;
    }

    return 0;
}
