#include <iostream>

using namespace std;

int main()
{
    long long unsigned int n;
    while(true) {
        cin >> n;
        if(n == -1)
            break;
        if(n >= 1)
            cout << n - 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
