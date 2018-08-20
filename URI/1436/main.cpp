#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t, n, x, j = 1;
    vector<int>v;
    cin >> t;
    while(t--) {
        v.clear();
        cin >> n;
        while(n--) {
            cin >> x;
            v.push_back(x);
        }
        int tam = (int)v.size() / 2;
        cout << "Case " << j++ << ": " << v[tam] << endl;
    }
    return 0;
}
