#include <iostream>

using namespace std;

int main()
{
    int t, n1;
    cin >> t;
    while(t--) {
        cin >> n1;
        if(n1 > 0)
            cout << n1 << " is positive number\n";
        else if (n1 < 0)
            cout << n1 << " is negative number\n";
        else
            cout << "n is zero\n";
    }
    return 0;
}
