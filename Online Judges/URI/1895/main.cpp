#include <iostream>

using namespace std;

int main()
{
    int n, to, l, x, a = 0, b = 0, veza = 1;
    cin >> n >> to >> l;
    n--;
    while(n--) {
        cin >> x;
        if(veza) {
            if(abs(to-x) <= l) {
                a+=abs(to-x);
                to = x;
            }
            veza = 0;

        } else {
            if(abs(to-x) <= l) {
                b+=abs(to-x);
                to = x;
            }
            veza = 1;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}
