#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long int n;
    vector<long long int>v;
    cin >> n;
    v.push_back(1);

    if(n != 1) {
        v.push_back(1);
        for(int i = 2; i < n; i++) {
            v.push_back(v[i - 2] + v[i - 1]);
        }
    }

    for ( int i = (int)v.size() - 1; i >= 0; i--) {
        if(i != (int)v.size() - 1)
            cout << " ";
        cout << v[i];
    }
    cout << endl;

    return 0;
}
