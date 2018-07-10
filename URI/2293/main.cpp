#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int> > v;
    int n, m, bigger, sum;
    cin >> n >> m;
    v.assign(n,vector<int>());

    for ( int i = 0; i < n; i++) {
        v[i].resize(m);
    }

    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    for ( int i = 0; i < n; i++) {
        sum = 0;
        for ( int j = 0; j < m; j++) {
            sum+=v[i][j];
        }
        if(i == 0)
            bigger = sum;
        if(sum > bigger)
            bigger = sum;
    }

    for ( int i = 0; i < m; i++) {
        sum = 0;
        for ( int j = 0; j < n; j++) {
            sum+=v[j][i];
        }

        if(sum > bigger)
            bigger = sum;
    }

    cout << bigger << endl;
    return 0;
}
