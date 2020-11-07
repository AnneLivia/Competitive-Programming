#include <iostream>

using namespace std;

int main() {
    int cont = 225, v;

    for (int i = 0; i < 5; i++) {
        cin >> v;
        switch (i)
        {
        case 0:
            cont+=(v*300);
            break;
        case 1:
            cont+=(v*1500);
            break;
        case 2:
            cont+=(v*600);
            break;
        case 3:
            cont+=(v*1000);
            break;
        case 4:
            cont+=(v*150);
            break;
        default:
            break;
        }
    }
    cout << cont << endl;
    return 0;  
}
