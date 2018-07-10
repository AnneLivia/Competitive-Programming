#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int t, t1, t2;
    cin >> t;
    while(t--) {
        cin >> t1 >> t2;
        printf("%d cm2\n",t2*t1/2);
    }
    return 0;
}
