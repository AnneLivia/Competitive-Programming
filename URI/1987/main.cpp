#include <iostream>

using namespace std;

int main()
{
    int qtdNumbers, sum;
    string number;
    bool stopped;
    while(cin >> qtdNumbers >> number) {
        sum = 0;
        while(qtdNumbers--)
        {
            sum +=(number[qtdNumbers] - '0');
        }
        if(sum % 3 == 0) {
            cout << sum << " sim\n";
        } else {
            cout << sum << " nao\n";
        }
    }
    return 0;
}
