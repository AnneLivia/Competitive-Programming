#include <iostream>

using namespace std;

int main()
{
    int a, c, x, y;

    cin >> a >> c >> x >> y;
    if(a <= ((c - 1) - (x + y))) {
        cout << "Igor feliz!\n";
    } else {
        if(x > (y/2))
            cout << "Caio, a culpa eh sua!\n";
        else
            cout << "Igor bolado!\n";
    }
    return 0;
}
