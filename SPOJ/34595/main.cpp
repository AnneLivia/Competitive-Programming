#include <iostream>

using namespace std;

int main()
{
    int t;
    double n1, n2;
    cin >>  t;
    while(t--) {
        cin >> n1 >> n2;
        if (n2 == 0)
            cout << "denominator cannot be zero\n";
        else
            cout << n1 / n2 << endl;
    }
    return 0;
}
