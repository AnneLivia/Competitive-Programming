#include <iostream>
#include <vector>

using namespace std;

void week(char p) {
    switch(p) {
        case '1' :
        case '2' : cout << "MONDAY\n";
                   break;
        case '3' :
        case '4' : cout << "TUESDAY\n";
                   break;
        case '5' :
        case '6' : cout << "WEDNESDAY\n";
                   break;
        case '7' :
        case '8' : cout << "THURSDAY\n";
                   break;
        case '9' :
        case '0' : cout << "FRIDAY\n";
                   break;
    }
}

int main()
{
    int t, ok;
    string p;
    cin >> t;
    cin.ignore();
    while(t--) {
        getline(cin,p);
        ok = 0;
        if(isalpha(p[0]) && p[0] != tolower(p[0])
           && isalpha(p[1]) && p[1] != tolower(p[1])
           && isalpha(p[2]) && p[2] != tolower(p[2])) {
            if(p[3] == '-') {
                for(int i = 4; i < (int) p.size(); i++) {
                    if((p[i] - '0') >= 0 && (p[i] - '0') <= 9) {
                        ok++;
                    } else {
                        break;
                    }
                }
                if(ok == 4)
                    week(p[7]);
                else
                    cout << "FAILURE\n";
            } else {
                    cout << "FAILURE\n";
            }
        } else {
            cout << "FAILURE\n";
        }
    }
    return 0;
}
