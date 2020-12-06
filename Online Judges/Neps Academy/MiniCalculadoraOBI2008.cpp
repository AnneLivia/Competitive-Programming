#include <iostream>

using namespace std;

int mdc(int n, int d) {
    if (d == 0)
        return n;
    return mdc(d, n % d);
}

int main() {
    int c, d, q, nd, nq, v;
    cin >> c >> d >> q;
    v = mdc(d,q);
    nd = d/v, nq = q/v;
    if (nd > c || nq > c ||  nd/nq > c || q == 0) 
        cout << "IMPOSSIVEL\n";
    else
        cout << nd << " " << nq << endl;
    
    return 0;  
}
