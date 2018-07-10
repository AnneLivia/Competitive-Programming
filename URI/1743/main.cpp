#include <iostream>

using namespace std;

int main()
{
    int vet1[5], vet2[5], flag = 0;
    for ( int i = 0; i < 5; i++) {
        cin >> vet1[i];
    }

    for ( int i = 0; i < 5; i++) {
        cin >> vet2[i];
    }

    for ( int i = 0; i < 5; i++) {
        if(vet1[i] == vet2[i]) {
            flag = 1;
            break;
        }
    }
    if(flag)
        cout << "N\n";
    else
        cout << "Y\n";
    return 0;
}
