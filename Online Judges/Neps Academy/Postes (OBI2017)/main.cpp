#include <iostream>

using namespace std;

int main()
{
    int n, v, conc = 0, sub = 0;
    cin >> n;
    while(n--) {
        cin >> v;
        if(v < 50) {
            sub++;
        } else if (v >= 50 && v < 85) {
            conc++;
        }
    }

    cout << sub << " " << conc << endl;
    return 0;
}
