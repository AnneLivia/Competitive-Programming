#include <iostream>

using namespace std;

long long unsigned int  mdc(long long unsigned int  a, long long unsigned int  b) {
    if(b == 0) {
        return a;
    } else {
        return mdc(b, a%b);
    }
}

int main()
{
    long long unsigned int n, m;
    cin >> n >> m;

    for (long long unsigned int  i = m;i >= 1; i--) {
        if(mdc(n, i) == 1) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
