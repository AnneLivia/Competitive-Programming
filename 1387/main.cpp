#include <iostream>

using namespace std;

int main()
{
    int r, l;
    while(true) {
        cin >> r >> l;
        if(r == 0 && l == 0)
            break;
        cout << l + r << endl;
    }
    return 0;
}
