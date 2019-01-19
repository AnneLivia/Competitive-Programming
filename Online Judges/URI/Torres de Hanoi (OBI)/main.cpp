#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
    long long unsigned int n, teste = 1;
    while(cin >> n && n != 0) {
        cout << "Teste " << teste++ << endl;
        printf("%llu\n",(long long unsigned int)pow(2,n) - 1);
        cout << endl;
    }
    return 0;
}
