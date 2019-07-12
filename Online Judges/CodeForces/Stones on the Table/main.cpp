#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    char vet[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> vet[i];
    }

    int take = 0;
    for (int i = 0; i < n - 1; i++) {
        if(vet[i] == vet[i + 1]) {
            take++;
        }
    }

    cout << take << endl;
    return 0;
}
