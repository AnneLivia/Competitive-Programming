#include <iostream>

using namespace std;

int main()
{
    int m, a, b, maxx;
    cin >> m >> a >> b;
    maxx = max(a,b);
    cout << max(maxx, m - (a + b)) << endl;
    return 0;
}
