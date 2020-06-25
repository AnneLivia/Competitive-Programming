#include <iostream>

using namespace std;

int main()
{
    int v[3], qtd = 0;

    for (int i = 0; i < 3; i++) {
        cin >> v[i];
    }


    for (int i = 0; i < 3; i++) {
        if (((v[i] & 1) == 0) || (v[i] % 10) == 5) {
            qtd++;
        }
    }

    cout << qtd << endl;
    return 0;
}
