#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<long long int>v;
    long long int t, k, m = 1000000007;
    long long unsigned sum;
    while(cin >> t >> k) {
        v.assign(t, 0);
        sum = 0;
        for (long long unsigned int i = 0; i < t; i++) {
            cin >> v[i];
        }
        sort(v.rbegin(),v.rend());
        for (long long unsigned int i = 0; i < k; i++) {
            sum = ((sum % m ) + (v[i] % m)) % m;
        }
        cout << sum << endl;
    }
    return 0;
}
