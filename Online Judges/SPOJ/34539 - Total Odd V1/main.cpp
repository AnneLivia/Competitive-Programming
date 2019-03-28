#include <iostream>

using namespace std;

int main()
{
    int n1, n2, qtd = 0;
    cin >> n1 >> n2;
    while(n1 <= n2) {
        if(n1++ % 2 != 0)
            qtd++;
    }

    cout << qtd << endl;
    return 0;
}
