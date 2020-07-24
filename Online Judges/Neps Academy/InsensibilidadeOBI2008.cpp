#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int d, x1, y1, x2, y2, qtd = 0;
    cin >> d;
    while(d--) {
        cin >> x1 >> y1 >> x2 >> y2;
        qtd+=((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));
    }    
    cout << qtd << endl;
    return 0;  
}
