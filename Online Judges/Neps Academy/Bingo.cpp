#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, b, sum, fail;    
    vector<int>v, num;
    while(cin >> n >> b && n && b) {
        fail = 0;
        v.assign(b, 0);
        num.assign(n+1, 0);

        for (int i = 0; i < b; i++) {
            cin >> v[i];
        }
        
        sort(v.begin(), v.end());

        for (int i = 0; i < b; i++) {
            for (int j = 0; j < b; j++) {
                if (i != j) {
                    sum = abs(v[i] - v[j]);
                    if (sum <= n) 
                        num[sum] = 1;
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (!num[i]) {
                fail = 1;
                break;
            } 
        }

        if (fail) {
            cout << "N\n";
        } else {
            cout << "Y\n";
        }
    }
    return 0;  
}
