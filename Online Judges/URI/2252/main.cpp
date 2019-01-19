#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(const pair<double,int>&p1, const pair<double,int>&p2) {
    return (p1.first > p2.first);
}

int main()
{
    vector<pair<double,int>>v;
    int d, cont, j = 1;
    double o;

    while(cin >> d) {
        v.clear();
        cont = 0;
        for(int i = 0; i < 10; i++) {
            cin >> o;
            v.push_back(make_pair(o,i));
        }

        sort(v.begin(),v.end(),compare);
        cout << "Caso " << j++ << ": ";
        for(int i = 0; i < d; i++)
            cout << v[i].second;
        cout << endl;
    }

    return 0;
}
