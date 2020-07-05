#include <iostream>

using namespace std;

int main()
{
    int v[10], me = 0x3f3f3f3f;
    for (int i = 0; i < 10; i++) {
        cin >> v[i];
        if (v[i] < me)
            me = v[i];
    }

    cout << "Menor: " << me << endl;
    cout << "Ocorrencias: ";
    for (int i = 0; i < 10; i++) {
        if (v[i] == me) {
            cout << i << " ";
            v[i] = -1;
        }
    }
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
