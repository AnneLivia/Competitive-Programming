#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, v;

    cin >> n >> v;

    for(int i = 10; i < 100; i+=10) {
        if(i != 10)
            cout << " ";
        cout << (int)ceil((n * v) * ( i / 100.0));
    }
    cout << endl;
    return 0;
}
