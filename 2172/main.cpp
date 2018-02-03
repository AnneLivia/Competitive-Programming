#include <iostream>

using namespace std;

int main()
{
    int m, x;
    while(true) {
        cin >> x >> m;
        if(m == 0 && x == 0)
            break;
        cout << m * x << endl;
    }
    return 0;
}
