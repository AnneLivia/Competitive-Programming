#include <iostream>

using namespace std;

int main()
{

    long long unsigned int n, res1, res2, res;
    cin >> n;


    res1 = n * (n - 1) * (n - 2) * (n - 3);
    res2 = n * (n - 1);
    res = 1 + (res2 / 2) + (res1 / 24);
    cout << res << endl;
    return 0;
}
