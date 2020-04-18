#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n, v[100001], c;
    memset(v, 0, sizeof(v)/sizeof(int));
    cin >> n;
    for (int i = 0; i < n-1; i++)
    {
        cin >> c;
        v[c] = 1;
    }


    for (int i = 1; i <= n; i++)
    {
        if (!v[i]) {
            cout << i << "\n";
            break;
        }
    }

    return 0;  
}
