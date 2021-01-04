#include <iostream>

using namespace std;

int main()
{
    int t = 1, to = 2, x = 2;
    for (int i = 0; i <= 30; i+=2) {
        for (int j = i+t; j <= i+t+1; j++) {
            cout << "a = " << i << " <-> b = " << j << endl;
        }
        t++;
    }

    return 0;
}
