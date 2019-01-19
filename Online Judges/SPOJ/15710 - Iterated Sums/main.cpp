#include <iostream>

using namespace std;

int main()
{
    int a1, a2, sum = 0;
    cin >> a1 >> a2;
    for(int i = a1; i <= a2; i++) {
        sum+=(i * i);
    }
    cout << sum << endl;
    return 0;
}
