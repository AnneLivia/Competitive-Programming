#include <iostream>

using namespace std;

int main()
{
    int a, b, c1 = 0, c2 = 0, fa, fb, qtd = 0;
    // c1 -> A turns on if turned off and vice versa
    // c2 -> A and B change its state

    cin >> a >> b >> fa >> fb;

    while(a != fa || b != fb) {
        if (b != fb) {
            a = !a;
            b = !b;
            qtd++;
        }

        if (a != fa) {
            a = !a;
            qtd++;
        }
    }
    cout << qtd << endl;
    return 0;
}
