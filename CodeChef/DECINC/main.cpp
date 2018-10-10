#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n % 4 == 0)
        cout << ++n << endl;
    else
        cout << --n << endl;

    return 0;
}
