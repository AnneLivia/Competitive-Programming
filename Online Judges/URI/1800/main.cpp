#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int q, e, n;
    vector<int>es;
    cin >> q >> e;
    while(e--) {
        cin >> n;
        es.push_back(n);
    }
    while(q--) {
        cin >> n;
        if(find(es.begin(), es.end(), n) != es.end()) {
            cout << "0\n";
        } else {
            cout << "1\n";
            es.push_back(n);
        }
    }
    return 0;
}
