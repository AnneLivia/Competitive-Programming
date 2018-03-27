#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int a,b,c = 0;
    double media = 0, mediana = 1;
    vector<int>v;
    while(true) {
        cin >> a >> b;
        c = 0;
        v.clear();
        media = 0;
        if(a == 0 && b == 0)
            break;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(), v.end());
        mediana = v[1];
        v[0] = 3 * v[1] - v[1] - v[2];
        cout << v[0] << endl;
    }
    return 0;
}
