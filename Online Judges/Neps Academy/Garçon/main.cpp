#include <iostream>

using namespace std;

int main()
{
    int qtd = 0, n, a, b;
    cin >> n;

    while(n--) {
        cin >> a >> b;
        if(a > b) {
            qtd+=b;
        }
    }
    cout << qtd << endl;
    return 0;
}
