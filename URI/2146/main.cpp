#include <iostream>

using namespace std;

int main()
{
    int password;

    while(cin >> password) {
        cout << password - 1 << endl;
    }
    return 0;
}
