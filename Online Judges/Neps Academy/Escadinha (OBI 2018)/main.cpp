#include <iostream>

using namespace std;

int main()
{
    int n, v[1001];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    v[n] = 0;
    int diff = 0x3f3f3f3f, cont = 1;
    for (int i = 0; i < n - 1;) {
        int ndif = v[i] - v[i + 1];
        if (ndif == diff || diff == 0x3f3f3f3f) {
            i++;
        } else {
            cont++;
        }
        diff = ndif;
    }
    cout << cont << endl;
    return 0;
}
