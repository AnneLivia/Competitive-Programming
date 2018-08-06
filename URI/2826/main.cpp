#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string a, b;
    vector<string>v;
    cin >> a >> b;
    v.push_back(a);
    v.push_back(b);

    sort(v.begin(),v.end());

    for(int i = 0; i < (int)v.size(); i++)
        cout << v[i] << endl;
    return 0;
}
