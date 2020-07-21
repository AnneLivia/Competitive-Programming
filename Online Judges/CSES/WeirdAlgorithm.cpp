#include <iostream>

using namespace std;

int main()
{
    long long int n;
    cin >> n;
    cout << n;
    while(n != 1) {
        if (!(n & 1)) {
            n = n >> 1;
        } else {
            n = n * 3;
            n+=1;
        }
        cout << " " << n;
    } while(n != 1);
    cout << endl;
    return 0;
}

