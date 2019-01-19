#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n, p, k, y = false;
    vector<int>v;
    cin >> n >> p;
    while(p--) {
        cin >> k;
        v.push_back(k);
    }

    for(int i = 0; i < (int)v.size() - 1; i++) {
        if(abs(v[i + 1] - v[i]) > n)
            y = true;
    }

    if(!y)
        cout << "YOU WIN\n";
    else
        cout << "GAME OVER\n";
    return 0;
}
