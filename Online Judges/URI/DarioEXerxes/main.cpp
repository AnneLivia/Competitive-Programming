#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
int main()
{
    int nr, d, x, contD, contX;
    vector<vi>v;
    v.assign(5,vi());
    v[0].push_back(1); v[0].push_back(2);
    v[1].push_back(3); v[1].push_back(2);
    v[2].push_back(3); v[2].push_back(4);
    v[3].push_back(0); v[3].push_back(4);
    v[4].push_back(0); v[4].push_back(1);
    contD = contX = 0;
    cin >> nr;
    while(nr--) {
        cin >> d >> x;
        if(find(v[d].begin(),v[d].end(),x) != v[d].end())
            contD++;
        if(find(v[x].begin(),v[x].end(),d) != v[x].end())
            contX++;
    }

    if(contD > contX)
        cout << "dario\n";
    else
        cout << "xerxes\n";

    return 0;
}
