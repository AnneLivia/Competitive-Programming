#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n;
    vector<int>v(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    cin >> k;

    sort(v.begin(), v.end());

    int i = 0, j = n - 1;
    while(i < j) {
        if (v[i] + v[j] == k) {
            cout << v[i] << " " << v[j] << endl;
            break;
        }
        if (v[i] + v[j] > k) {
            j--;
        } else {
            i++;   
        }
    }
    return 0;  
}
