#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, t, a, b;
    cin >> n >> t;    
    // side 1 = up, 0 = down
    vector<int>up(n, 0), down(n, 0), side(n, 1);
    for (int i = 0; i < n; i++)
    {
        cin >> up[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> down[i];
    }
    
    while(t--) {
        cin >> a >> b;
        --a; --b;
        for (int i = a; i <= b; i++) {
            side[i] = !side[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            cout << " ";
        if (side[i]) 
            cout << up[i];
        else
            cout << down[i];
    }
    cout << endl;
    return 0;  
}
