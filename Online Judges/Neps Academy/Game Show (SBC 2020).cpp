#include <iostream>

using namespace std;

int main() {

    int n, v, amount = 100, sum = 100;
    cin >> n;

    while(n--) {
        cin >> v;
        sum+=v;
        if (sum > amount) {
            amount = sum;
        }
    }

    cout << amount << endl;
    return 0;
}
