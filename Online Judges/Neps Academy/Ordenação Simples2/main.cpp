#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int>v(10, 0);
    for (int i = 0; i < 10; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < 10; i++) {
        if(i != 0)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
     for (int i = 9; i >= 0; i--) {
        if(i != 9)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
    return 0;
}
