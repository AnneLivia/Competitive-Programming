#include <iostream>

using namespace std;

int main()
{
    string vet[10];
    for ( int i = 0; i < 10; i++) {
        cin >> *(vet + i);
    }
    cout << vet[2] << endl;
    cout << vet[6] << endl;
    cout << vet[8] << endl;
    return 0;
}
