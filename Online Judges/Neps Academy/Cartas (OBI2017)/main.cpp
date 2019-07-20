#include <iostream>

using namespace std;

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    if(n1 == n2)
        cout << n3 << endl;
    else if (n2 == n3) {
        cout << n1 << endl;
    } else if (n1 == n3) {
        cout << n2 << endl;
    }
    return 0;
}
