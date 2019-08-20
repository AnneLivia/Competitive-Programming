#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<float>v(5, 0);
    float sum = 0.0;
    for (int i = 0; i < 5; i++) {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    for (int i = 1; i < 4; i++) {
        sum+=v[i];
    }
    cout.precision(1);
    cout.setf(ios::fixed);
    cout << sum << endl;
    return 0;
}
