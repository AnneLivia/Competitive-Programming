#include <iostream>

using namespace std;

int main()
{
    int n1, n2;
    cin >> n1 >> n2;

    if (n1 >= 0 && n1 <= 432 && n2 >= 0 && n2 <= 468) {
        cout << "dentro\n";
    } else {
        cout << "fora\n";
    }
    return 0;
}
