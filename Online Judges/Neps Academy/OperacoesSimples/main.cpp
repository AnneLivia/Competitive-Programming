#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void insersionSort(vector<int>& v) {
    for (int i = 1; i < (int)v.size(); i++) {
        int number = v[i], j = i - 1;
        while(number < v[j] && j >= 0) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = number;
    }
}

int main () {

    int n;
    cin >> n;
    vector<int>v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if(i != 0)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
    return 0;
}
