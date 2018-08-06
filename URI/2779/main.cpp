#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, nn, cont = 0, m;
    vector<int>v;
    cin >> n;
    v.assign(n+1,0);
    cin >> m;
    while(m--) {
        cin >> nn;
        v.at(nn) = 1;
    }

    for (int i = 1; i < (int)v.size(); i++) {
        if(v[i] != 1)
            cont++;
    }

    cout << cont << endl;
    return 0;
}
