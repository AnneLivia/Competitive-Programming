#include <iostream>

using namespace std;

int main()
{
    char bit[102];
    int i = 0, cont1 = 0;
    cin >> bit;
    while(bit[i]) {
        if(bit[i] == '1')
            cont1++;
        i++;
    }
    if(cont1 % 2 == 0)
        bit[i] = '0';
    else
        bit[i] = '1';
    bit[++i] = '\0';
    cout << bit << endl;
    return 0;
}
