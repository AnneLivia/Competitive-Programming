#include <iostream>

using namespace std;

bool is_prime(long long unsigned int n) {
    if(n <= 1)
        return false;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    long long unsigned int cTestes, value;
    cin >> cTestes;
    while(cTestes--) {
        cin >> value;
        if(is_prime(value))
            cout << "Prime\n";
        else
            cout << "Not Prime\n";
    }
    return 0;
}
