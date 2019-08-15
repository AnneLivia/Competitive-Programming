#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, cont = 0;
    cin >> n;
    vector<int>v(n,0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n - 2; i++) {
        if(v[i] == 1 && v[i + 1] == 0 && v[i + 2] == 0)
            cont++;
    }

    cout << cont << endl;
    return 0;
}
