#include <vector>
#include <iostream>
using namespace std;

int main( ) {
    int n;
    string alg;
    vector<int>v(10, 0);
    cin >> n;
    while(n--) {
        cin >> alg;
        for (int i = 0; i < (int)alg.size(); i++) {
            v[alg[i] - '0']++;
        }
    }

    for (int i = 0; i <= 9; i++) {
        cout << i << " - " << v[i] << endl;
    }
    return 0;
}
