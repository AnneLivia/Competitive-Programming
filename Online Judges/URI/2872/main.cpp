#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    string pack, num;
    vector<string>v;
    while(cin >> n) {
        v.clear();
        while(cin >> pack && pack != "0") {
            cin >> num;
            v.push_back(num);
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++) {
            cout << "Package " << v[i] << endl;
        }
        cout << endl;
    }
    return 0;
}
