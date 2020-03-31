#include <iostream>

using namespace std;

int main()
{
    int n, c, total = 0;
    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        total+=c;
        if (c > 1)
            c--;
    }
    cout << total << endl;
    return 0;
}
