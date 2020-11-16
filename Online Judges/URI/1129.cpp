#include <iostream>

using namespace std;

int main() {

    int n, v[5];
    while(cin >> n && n) {

        while(n--) {
            int minin = -1, wrong = 0;
            for (int i = 0; i < 5; i++) {
                cin >> v[i];
                if (v[i] <= 127) {
                    if (minin == -1)
                        minin = i;
                    else
                        wrong = 1;
                }
            }

            if (wrong || minin == -1) {
                cout << "*\n";
            } else {
                cout << (char)('A' + minin) << endl;
            }
        }
    }
    return 0;
}
