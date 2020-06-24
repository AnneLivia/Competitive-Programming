#include <iostream>

using namespace std;

int lookup[1000] = {0};

int fibTopDown(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    if (lookup[n] != 0) {
        return lookup[n];
    }

    return lookup[n] = fibTopDown(n - 1) + fibTopDown(n - 2);
}

int main()
{
    int n, v[1000];
    cin >> n;
    v[0] = 0;
    v[1] = 1;

    // bottom up DP
    for (int i = 0; i < n; i++) {
        if (i > 1)
            v[i] = v[i - 1] + v[i - 2];
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
