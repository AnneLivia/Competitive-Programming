#include <iostream>

using namespace std;

int main()
{
    int n1, n2, aux1, aux2, q, rest;
    cin >> n1 >> n2;
    if(n1 < 0) {
        aux1 = n2;
        if(n2 < 0)
            aux1 = n2 * -1;
        for(rest = 0; rest < aux1; rest++)
        {
            aux2 = n1 - rest;
            if(aux2 % n2 == 0)
                break;
        }
        q = aux2 / n2;
    } else {
        q = n1 / n2;
        rest = n1 % n2;
    }
    cout << q << " " << rest << endl;
    return 0;
}
