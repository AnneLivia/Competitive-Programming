#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;

    cin >> n;

    vector<int>v(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int meio = n/2;
    if (n % 2 == 0)
        meio--;

    cout << v[0] << "\n" << v[meio] << "\n" << v[n-1] << endl;

    return 0;
}
