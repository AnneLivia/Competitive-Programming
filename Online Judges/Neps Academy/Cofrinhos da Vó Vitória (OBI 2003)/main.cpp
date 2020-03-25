#include <iostream>

using namespace std;

int main()
{
    int j, z, n, i, b, t = 1;

    while(cin >> n && n) {
        j = z = 0;
        cout << "Teste " << t++ << endl;
        while(n--) {
            cin >> i >> b;
            j+=i; z+=b;
            cout << j - z << endl;
        }
        cout << endl;
    }
    return 0;
}
