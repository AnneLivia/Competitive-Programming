#include <iostream>
#include <cmath>

using namespace std;

bool prime(long long int n) {
    for(long long int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0)
          return false;
    } 
    return true;
}

int main() {
    long long int n;
    cin >> n;
    if (n >= 4 && !prime(n)) 
        cout << "S\n";
    else 
        cout << "N\n";

    return 0;  
}
