#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n;
    vector<int>v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cin >> k;

    int i = 0, j = n - 1;
    while(i < j) {
        int sum = v[i] + v[j];
        if(sum == k) {
            cout << v[i] << " " << v[j] << endl;
            break;
        } else if (sum > k) {
            j--;
        } else {
            i++;
        }
    }
    return 0;
}
