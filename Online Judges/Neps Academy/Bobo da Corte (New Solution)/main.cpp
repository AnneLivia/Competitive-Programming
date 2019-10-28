#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>v(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    if(*(max_element(v.begin(), v.end())) == v[0]) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }
    return 0;
}
