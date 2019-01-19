#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    int cop;
    while(cin >> n) {
        cop = log2(n);
        cout << cop << endl;
    }
    return 0;
}
