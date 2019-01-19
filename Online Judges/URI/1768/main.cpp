#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n, k;
    while(cin >> n) {
        k = n/2 + 1;
        for(int i = 1; i <= n; i+=2) {
            cout << setw(k--);
            for(int j = 0; j < i; j++) {
                cout << "*";
            }
            cout << endl;
        }
        cout << setw(((n/2)+1)) << "*";
        cout << "\n";
        cout << setw(((n/2)+2)) << "***";
        cout << endl;
        cout << endl;
    }
    return 0;
}
