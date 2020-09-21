#include <iostream>

using namespace std;

int main() {
    int a, b, c, qtd = 0;
    cin >> a >> b >> c;    

    while(a >= 2 && b >= 3 && c >= 5) {
        qtd++;
        a-=2;
        b-=3;
        c-=5;
    }
    cout << qtd << endl;
    return 0;  
}
