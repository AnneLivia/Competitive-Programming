#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, p;

    cin >> n >> p;

    int total = n * p;

    for (int i = 10; i <= 90; i+=10) {
        if(i != 10)
            cout << " ";
        cout << (int)ceil(total * (i / 100.00));
    }
    cout << endl;
    return 0;
}
