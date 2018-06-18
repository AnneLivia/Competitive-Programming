#include <iostream>

using namespace std;

int main()
{
    int l, c;
    cin >> l >> c;
    if(l % 2 != 0 && c % 2 == 0 ||
       l % 2 == 0 && c % 2 != 0)
        cout << 0 << endl;
    else
        cout << 1 << endl;
    return 0;
}
