#include <iostream>

using namespace std;

bool isPrime(long long int n) {
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
    long long int mult, stop, n, aux;
    int v, largest = -1;

    v = 2, mult = 1, stop = 1, n = 600851475143, aux = 600851475143;
    while(stop < n && mult < n) {
        if(aux % v == 0) {
            if (isPrime(v)) {
                mult*=v;
                if(v > largest)
                    largest = v;
            } else {
                stop*=v;
            }
            aux = aux / v;
        } else {
            v++;
        }
    }

    if(stop == 1)
        cout << largest << endl;
    else
        cout << "Not\n";
    return 0;
}
