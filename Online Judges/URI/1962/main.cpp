#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long int year;
    int n;
    cin >> n;
    while(n--) {
        cin >> year;
        if(year >= 2015) {
            cout << year - 2015 + 1 << " A.C.\n";
        } else {
            cout << 2015 - year << " D.C.\n";
        }
    }
    return 0;
}
