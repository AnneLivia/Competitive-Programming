#include <iostream>

using namespace std;

int main()
{
    int n = 1, m = 0;
    while(n != 0) {
        cin >> n;
        if(n > m)
            m = n;
    }
    cout << m << endl;
    return 0;
}
