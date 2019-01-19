#include <iostream>

using namespace std;

int main()
{
    int a, b, c, f1, f2, f3;
    cin >> a >> b >> c;

    f1 = 4 * c + 2 * b;
    f2 = (2 * c) + (2 * a);
    f3 = (4 * a) + (2 * b);

    if(f1 <= f2 && f1 <= f3)
        cout << f1 << endl;
    else if (f2 <= f1 && f2 <= f3)
        cout << f2 << endl;
    else
        cout << f3 << endl;
    return 0;
}
