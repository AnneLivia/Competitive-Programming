#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, cm, v, p, cont = 0;
    bool flag = false;

    cin >> n >> cm;
    while(n--) {
        cin >> v >> p;
        cont = cont - v;
        cont = cont + p;
        if(cont > cm)
            flag = true;
    }

    if(flag)
        cout << "S\n";
    else
        cout << "N\n";
    return 0;
}
