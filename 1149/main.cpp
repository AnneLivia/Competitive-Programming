#include <iostream>

using namespace std;

int main()
{
    int A, N, soma = 0;
    cin >> A;
    do {
        cin >> N;
    } while (N <= 0);

    for (int i = 0; i < N; i++)
    {
        soma = A + i + soma;
    }
    cout << soma << endl;
    return 0;
}
