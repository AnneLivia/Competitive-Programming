#include <iostream>

using namespace std;

bool isPrime(int n) {
    if(n <= 1)
        return false;
    int div = 2;

    while(div <= n / 2) {
        if(n % div == 0)
            return false;
        div++;
    }
    return true;
}

int main()
{
    int qtdPrime = 0, i = 1;
    while(qtdPrime < 10001) {
        i++;
        if(isPrime(i)) {
            qtdPrime++;
        }
    }

    cout << i << endl;
    return 0;
}
