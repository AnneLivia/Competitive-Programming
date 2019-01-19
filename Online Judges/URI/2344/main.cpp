#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n == 0)
        cout << "E\n";
    else if (n >= 1 && n <= 35)
        cout << "D\n";
    else if (n >= 36 && n <= 60)
        cout << "C\n";
    else if (n >= 61 && n <= 85)
        cout << "B\n";
    else if (n >= 86 && n <= 100)
        cout << "A\n";
    return 0;
}
