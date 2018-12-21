#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long unsigned int n, x, i;
    long long unsigned int contVis, contStole, total = 0;
    vector<long long unsigned int>v, vis;

    cin >> n;
    v.assign(n, 0);
    vis.assign(n, 0);

    for (i = 0; i < n; i++) {
        cin >> v[i];
        total+=v[i];
    }

    i = contStole = contVis = 0;
    while(i >= 0 && i < n) {
        if(!vis[i]) {
            contVis++;
            vis[i] = 1;
        }

        if(v[i] != 0) {
            int pos = i;
            if(v[i] % 2 == 0)
                i--;
            else
                i++;
            contStole++;
            v[pos]--;
        } else {
            i--;
        }
    }

    cout << contVis << " " << total - contStole << endl;
    return 0;
}
