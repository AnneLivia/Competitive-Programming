#include <iostream>

using namespace std;

int main()
{
    int m;
    cin >> m;
    cout << m / 60 << endl;
    cout << m - ((m / 60) * 60) << endl;
    return 0;
}
