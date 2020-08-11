#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, c, s, va, po = 1, cont = 0;
    cin >> n >> c >> s;
    for (int i = 0; i < c+1; i++) {
        if ( i < c)
            cin >> va;
        if (po == s)
            cont++;
        po+=va;
        if (po <= 0)
            po = n;
        else if (po > n)
            po = 1;
   }
    
    cout << cont << endl;
    return 0;
}