#include <iostream>

using namespace std;

int main() {
    int n, qtd = 1;
    cin >> n;
    while(n >= 2) {
        qtd*=4;
        n/=2;
    }    
    cout << qtd << endl;
    return 0;  
}
