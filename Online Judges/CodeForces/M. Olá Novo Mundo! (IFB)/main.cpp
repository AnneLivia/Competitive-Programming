#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<char, string> mn = {
        {'A', "Hallo neue welt!"},
        {'E', "Hola nuevo mundo!"},
        {'F', "Bonjour le nouveau monde!"},
        {'I', "Hello new world!"},
        {'P', "Ola novo mundo!"},
        {'T', "Ciao nuovo mondo!"}
    };

     map<char, int> msn = {
        {'A', 0},
        {'E', 0},
        {'F', 0},
        {'I', 0},
        {'P', 0},
        {'T', 1}
    };

    int m, n, p;
    cin >> m >> n >> p;
    char c;
    cout << mn['T'] << endl;
    for (int i = 0; i < m + n + p; i++) {
        cin >> c;
        if(msn[c] == 0) {
            cout << mn[c] << endl;
            msn[c] = 1;
        }
    }
    return 0;
}
