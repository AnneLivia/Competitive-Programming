#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    long long int n1, n2;
    while(cin >> n1 >> n2) {
        cout << max(n1,n2) - min(n1,n2) << endl;
    }
    return 0;
}
