#include <iostream>

using namespace std;

int main()
{
    int n1, n2, aux;
    cin >> n1 >> n2;
    if (n1 > n2) {
       aux = n1;
       n1 = n2;
       n2 = aux;
    }


    for (int i = n1; i <= n2; i++) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
