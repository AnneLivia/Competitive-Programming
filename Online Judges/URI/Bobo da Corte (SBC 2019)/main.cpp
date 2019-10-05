#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, cont = 0;

    cin >> n;

    vector<int>v(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int maximum = -1;
    for (int i = 0; i < n; i++) {
        if(maximum < v[i]) {
            maximum = v[i];
        }
    }

    if(maximum == v[0]) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }
    return 0;
}
