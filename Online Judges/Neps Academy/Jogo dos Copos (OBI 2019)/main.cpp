#include <iostream>

using namespace std;

int main()
{
    int t, v;
    char po;
    cin >> t >> po;
    while(t--) {
        cin >> v;
        if (v == 1) {
            if (po == 'A' || po == 'B')
                po = po == 'A' ? 'B' : 'A';
        } else if (v == 2) {
            if (po == 'B' || po == 'C')
                po = po == 'B' ? 'C' : 'B';
        } else if (v == 3) {
            if (po == 'C' || po == 'A')
                po = po == 'C' ? 'A' : 'C';
        }
    }
    cout << po << endl;
    return 0;
}
