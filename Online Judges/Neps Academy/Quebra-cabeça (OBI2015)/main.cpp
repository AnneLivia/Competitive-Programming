#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct piece {
    int fim;
    char letter;
};

int main()
{
    int n, ini;
    cin >> n;
    piece p;
    // first number is the last number of some piece if it's not 0
    // which is the beginning of the jigsaw puzzle or 1 which is the end

    vector<piece>quebra(2000001, {0,'0'});

    for (int i = 0; i < n; i++) {
        cin >> ini >> p.letter >> p.fim;
        quebra[ini] = p;
    }

    for (int i = 0; i != 1; i = quebra[i].fim) {
        cout << quebra[i].letter;
    }
    cout << endl;
    return 0;
}
