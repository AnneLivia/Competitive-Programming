#include <iostream>
#include <stdio.h>
using namespace std;

int main() {

    double raio;
    const double pi = 3.14159;
    cin >> raio;
    printf("VOLUME = %.3f\n",(4/3.0)*pi*(raio * raio * raio));
    return 0;
}
