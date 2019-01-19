#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int j, n, lastImp = 0, va, k;
    vector<int>v;
    cin >> j >> n;
    v.assign(j,0);
    while(n--) {
        k = 0;
        for(int i = 0; i < j; i++) {
            cin >> va;
            v[k]+=va;
            if(v[k] >= v[lastImp])
                lastImp = k;
            k++;
        }
    }


    cout << lastImp + 1 << endl;
    return 0;
}
