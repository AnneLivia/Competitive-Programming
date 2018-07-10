#include <iostream>

using namespace std;

int main()
{
    int n, listNumbers, qtdM2,qtdM3,qtdM4, qtdM5;
    qtdM2 = qtdM3 = qtdM4 = qtdM5 = 0;
    cin >> n;
    while(n--) {
        cin >> listNumbers;
        if(listNumbers % 2 == 0)
            qtdM2++;
        if(listNumbers % 3 == 0)
            qtdM3++;
        if(listNumbers % 4 == 0)
            qtdM4++;
        if(listNumbers % 5 == 0)
            qtdM5++;
    }
    cout << qtdM2 << " Multiplo(s) de 2\n";
    cout << qtdM3 << " Multiplo(s) de 3\n";
    cout << qtdM4 << " Multiplo(s) de 4\n";
    cout << qtdM5 << " Multiplo(s) de 5\n";
    return 0;
}
