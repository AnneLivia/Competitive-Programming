#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int t, n[6];
    bool yes[7], no;
    cin >> t;
    while(t--) {
        memset(yes,false,7);
        no = false;
        for ( int i = 0; i < 6; i++) {
            cin >> n[i];
            if(n[i] >= 1 && n[i] <= 6)
                yes[n[i]] = true;
        }

        for ( int i = 1; i <= 6; i++) {
            if(!yes[i])
                no = true;
        }
        if(!no) {
            if(n[0] + n[5] == 7 && n[1] + n[3] == 7 && n[2] + n[4] == 7)
                cout << "SIM\n";
            else
                cout << "NAO\n";
        } else {
            cout << "NAO\n";
        }
    }
    return 0;
}
