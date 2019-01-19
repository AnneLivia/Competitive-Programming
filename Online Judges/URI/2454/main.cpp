#include <iostream>

using namespace std;

int main()
{
    int door1, door2;
    cin >> door1 >> door2;
    if(!door1) {
        cout << "C\n";
    } else if (door1 && door2)
        cout << "A\n";
    else if (door1 && !door2)
        cout << "B\n";
    return 0;
}
