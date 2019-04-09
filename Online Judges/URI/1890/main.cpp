#include <iostream>

using namespace std;

int pow(int n, int b) {
    if(b == 0)
        return 1;
    else
        return n * pow(n, b - 1);
}

int main()
{
    int n, c, d, res;
    cin >> n;
    while(n--) {
        cin >> c >> d;
        res = 0;
        if(c != 0 || d != 0) {
            res = pow(26,c) * pow(10, d);
        }
        cout << res << endl;
    }
    return 0;
}
