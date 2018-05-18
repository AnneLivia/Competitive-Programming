#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main()
{
    int t, n;
    string type;
    cin >> t;
    while(t--) {
        cin >> n >> type;
        if(type.compare("bin")) {
            cout << dec << n << endl;
            cout << hex << n << endl;
        } else if (type.compare("dec")) {
            cout << hex << n << endl;
        } else {
            cout << dec << n << endl;
        }
    }
    return 0;
}
