#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        int cont = 0;
        if(i - 1 >= 0)
            cont+=v[i - 1];
        if(i + 1 < n)
            cont+=v[i + 1];
        cout << cont + v[i] << endl;
    }
    return 0;
}
