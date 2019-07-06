#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, c = 0;
    cin >> n;
    vector<int>v(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 1; i < n - 1; i++) {
        if(v[i] < v[i - 1] && v[i + 1] < v[i] ||
           v[i] < v[i + 1] && v[i - 1] < v[i]) {
            c++;
        }
    }

    cout << c << endl;
    return 0;
}
