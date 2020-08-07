#include <iostream>

using namespace std;

int main()
{
    int v1, v2, v3, v4;
    cin >> v1 >> v2 >> v3 >> v4;
    if (v1 < v2 + v3 && v2 < v1+v3 && v3 < v2 + v1 ||
        v1 < v2 + v4 && v2 < v1+v4 && v4 < v1 + v2 ||
        v4 < v2 + v3 && v2 < v4+v3 && v3 < v4 + v2 ||
        v1 < v3 + v4 && v4 < v1+v3 && v3 < v4 + v1) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }
    return 0;
}
