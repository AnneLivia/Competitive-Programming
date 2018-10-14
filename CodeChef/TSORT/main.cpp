#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, t;

    cin >> t;

    int v[t];

    for(int i = 0; i < t; i++){
        cin >> n;
        v[i] = n;
    }

    sort(v,v+t);

    for(int i = 0; i < t; i++)
        cout << v[i] << endl;
    return 0;
}
