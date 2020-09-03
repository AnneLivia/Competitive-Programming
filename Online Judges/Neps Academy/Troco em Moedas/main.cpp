#include <iostream>

using namespace std;

int main()
{
    int c, qtd = 0;
    // 1, 50, 25, 10, 5, 0.1
    int cc[6] = {0};
    cin >> c;
    // 1 real
    while(c >= 100) {
        cc[0]++;
        c-=100;
        qtd++;
    }

    while(c >= 50) {
        cc[1]++;
        c-=50;
        qtd++;
    }

    while(c >= 25) {
        cc[2]++;
        c-=25;
        qtd++;
    }

    while(c >= 10) {
        cc[3]++;
        c-=10;
        qtd++;
    }

    while(c >= 5) {
        cc[4]++;
        c-=5;
        qtd++;
    }

    while(c >= 1) {
        cc[5]++;
        c-=1;
        qtd++;
    }

    cout << qtd << endl;
    for (int i = 0; i < 6; i++) {
        cout << cc[i] << endl;
    }


    return 0;
}
