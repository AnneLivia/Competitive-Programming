#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int l, c, x, y;
    cin >> l >> c >> x >> y;
    x+=1; y+=1;

    long long int k = x - 1;

    k*=c;
    k+=y;

    if(k%2 != 0)
        cout << "Direita\n";
    else
        cout << "Esquerda\n";
    return 0;
}
