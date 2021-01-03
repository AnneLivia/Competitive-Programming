#include <iostream>

using namespace std;

int main()
{

    for (int i = 12, j = 18; i <= 32; i++, j++) {
        cout << "a = " << i << " <-> b = " << j << endl;
        cout << "a = " << i + 2 << " <-> b = " << j - 2 << endl;
        cout << "a = " << i + 6 << " <-> b = " << j - 6 << endl;
    }
    return 0;
}
