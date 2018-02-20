#include <iostream>

using namespace std;

int main()
{
    int qtdMar, num, qtdJohn, qtdGames;
    while(true) {
        qtdJohn = qtdMar = 0;
        cin >> qtdGames;
        if(!qtdGames) {
            break;
        }
        while(qtdGames--) {
            cin >> num;
            if(num == 0)
                qtdMar++;
            else
                qtdJohn++;
        }
        cout << "Mary won " << qtdMar << " times and John won " << qtdJohn << " times\n";
    }

    return 0;
}
