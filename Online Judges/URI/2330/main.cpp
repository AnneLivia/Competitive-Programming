#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {

    priority_queue<pair<int, int >, vector<pair<int,int> >, greater<pair<int,int> > > pq;

    int n, l, t;
    cin >> n >> l;
    vector<int>cont(n, 0);

    for (int i = 0; i < n; i++) {
        pq.push({0, i});
    }

    while(l--) {
        cin >> t;
        pair<int,int> pp = pq.top();
        pq.pop();
        cont[pp.second]++;
        pq.push({t+pp.first, pp.second});
    }

    for (int i = 0; i < n; i++) {
        cout << i + 1 << " " << cont[i] << endl;
    }
    return 0;
}
