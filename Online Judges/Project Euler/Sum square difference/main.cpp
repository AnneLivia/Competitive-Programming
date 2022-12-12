#include <iostream>

using namespace std;

int main()
{
    int sums = 0, ssum = 0;
    for (int i = 1; i <= 100; i++) {
        sums+=(i * i);
        ssum+=i;
    }
    ssum*=ssum;
    cout << ssum - sums << endl;
    return 0;
}
