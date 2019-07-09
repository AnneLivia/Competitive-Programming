#include <iostream>
#include <cmath>

using namespace std;

/*
    The amount of movements done to solve the problem of
    HANOI with n circles is 2^n - 1.

    Basically, this problem can be solved recursively, by solving it's smaller
    parts, for example: for 3 circles, it can be solved the 2 circles, solve then the 1 circle.

*/

int qtd = 0;
void hanoi(int qtd_discos, char origem, char intermediario, char destino) {
    if(qtd_discos == 1) {
        //cout << "move " << qtd_discos << " From " << origem << " to " << destino << endl;
    } else {
        // move all discs to the intermediate position and uses the exactly finish position as intermediate
        hanoi(qtd_discos - 1, origem, destino, intermediario);
        //cout << "move " << qtd_discos << " From " << origem << " to " << destino << endl;
        // now fix the problem by putting all discs in the intermediate position in the finish position, since the
        // last disc is already in its right position. Here origin is used as a intermediate position.
        hanoi(qtd_discos - 1, intermediario, origem, destino);
    }
    qtd++;
 }

int main()
{
    int n, t  = 1;

    while(cin >> n && n) {
        cout << "Teste " << t++ << endl;
        long long unsigned int res = (long long unsigned int)pow(2, n) - 1;
        cout << res << endl << endl;
    }
    return 0;
}
