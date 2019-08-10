#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int>v(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int sub = 0, bsub = -1, i = 0;

    while(i < n) {
        if(v[i] == v[i + 1]) {
            sub++;
        } else {
            sub++;
            if(sub > bsub)
                bsub = sub;
            sub = 0;
           //i--;
        }
        i++;
    }
    cout << bsub << endl;
    return 0;
}
