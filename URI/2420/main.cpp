#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, va, ind, sum = 0, wsum = 0;
    vector<int>v;
    cin >> n;
    while(n--) {
        cin >> va;
        v.push_back(va);
        wsum += va;
    }

    for ( int i = 0; i < (int)v.size(); i++) {
        sum += v[i];
        if(sum == (wsum - sum)) {
            ind = i;
            break;
        }
    }

    cout << ind + 1 << endl;
    return 0;
}
