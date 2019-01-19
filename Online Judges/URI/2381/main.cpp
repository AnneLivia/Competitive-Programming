#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    string name;
    vector<string>p;
    cin >> n >> k;
    while(n--) {
        cin >> name;
        p.push_back(name);
    }

    sort(p.begin(),p.end());

    cout << p[k - 1] << endl;
    return 0;
}
