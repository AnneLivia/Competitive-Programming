#include <iostream>

using namespace std;

int main()
{
    long long unsigned int n;
    bool likes = true;
    cin >> n;
    /*
        numbers one less than a power of 2 are all 1s),
        with a special case check for zero
    */
    if ((((n+1) & n) == 0) && n != 0)
        cout << "S\n";
    else
        cout << "N\n";
    return 0;
}
