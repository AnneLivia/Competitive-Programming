#include <iostream>

using namespace std;

int main()
{
    char c;
    int cont = 0, t;
    cin >> t;
    while(t--) {
        cin >> c;
        if (c == 'P' || c == 'C') {
            cont+=2;
        } else if (c == 'A') {
            cont+=1;
        }
    }
    cout << cont << endl;
    return 0;
}
