#include <iostream>

using namespace std;

int main()
{
    int v, a, b, c, d, t = 1;
    while(cin >> v && v) {
        a = 0, b = 0, c = 0, d = 0;
        while(v >= 50) {
            v-=50;
            a++;
        }
        while(v >= 10) {
            v-=10;
            b++;
        }
        while(v >= 5) {
            v-=5;
            c++;
        }
        while(v >= 1) {
            v-=1;
            d++;
        }
        cout << "Teste " << t++ << endl;
        cout << a << " " << b << " " << c << " " << d << endl << endl;
    }
    return 0;
}
