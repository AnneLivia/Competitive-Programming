#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int nj, np, v, qtdAll = 0, sp;
    cin >> nj >> np;

    while(nj--) {
        sp = 0;
        for(int i = 0; i < np; i++) {
            cin >> v;
            if(v != 0)
                sp++;
        }

        if(sp == np)
            qtdAll++;
    }

    cout << qtdAll << endl;
    return 0;
}
