#include <iostream>

using namespace std;

/* Euclides algorithm to find maximum common divisor
    Is a method to find the MDC between two numbers by doing successive division
    MDC is the largest integer that divides both number.

    The idea behind  this algorithm is that the MDC can be calculated recursively
    using the remainder as argument to the next call to the function:
    MDC(a,b) = MDC(b,r) where r is the remainder of a and b
*/
typedef long long int lli;

lli mdc(lli a, lli b) {
    if (a % b == 0) {
        // if remainder is 0, then return b
        return b; // last remainder different of 0
    }

    return mdc(b, a%b);
}

int main()
{
    lli a, b, c, d, sum1, sum2;
    cin >> a >> b >> c >> d;
    sum2 = b * d;
    sum1 = (a*d) + (b*c);

    lli mm = mdc(sum2, sum1);

    cout << sum1/mm << " " << sum2/mm << endl;

    return 0;
}
