#include <iostream>

using namespace std;

int main() {
    int a, b, chaira = 0, chairb = 0, chairc;
    cin >> a >> b;
    while(a--) {
        chaira++;
        if (chaira > 2)
            chaira = 0;
    }

    while(b--) {
        chairb++;
        if (chairb > 2)
            chairb = 0;
    }

    if(chairb == chaira) {
        chairb++;
        if (chairb > 2)
            chairb = 0;
    }

    
    chairc = 0;
    while(chairc == chaira || chairb == chairc) 
        chairc++;
    
    cout << chairc << endl;

    return 0;   
}
