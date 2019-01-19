#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, va;
    vector<int>ve;
    vector<int>fv;
    cin >> n;
    fv.assign(n,0);
    while(n--) {
        cin >> va;
        ve.push_back(va);
    }

    for ( int i = 0; i < (int)ve.size(); i++) {
        if(i == 0)
            fv[i] = ve[i + 1] + ve[i];
        else if (i == (int)ve.size() - 1)
            fv[i] = ve[i - 1] + ve[i];
        else {
            fv[i] = ve[i - 1] + ve[i] + ve[i + 1];
        }
    }

    for(auto i : fv)
        cout << i << endl;

    return 0;
}
