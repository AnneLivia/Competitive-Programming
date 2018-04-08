#include <iostream>

using namespace std;

int main()
{
    int va, tp, n;
    cin >> va >> tp;
    while(tp--) {
        cin >> n;
        va+=n;
        if(va < 0)
            va = 0;
        else if (va > 100)
            va = 100;
    }

    cout << va << endl;
    return 0;
}
