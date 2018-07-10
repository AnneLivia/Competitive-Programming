#include <iostream>

using namespace std;

int main()
{
    int t, x, y, flag = false, vet[1000][1000] = {0};
    cin >> t;
    while(t--) {
        cin >> x >> y;
        if(!flag && vet[x][y] == 1)
            flag = true;
        vet[x][y] = 1;
    }

    if(flag)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}
