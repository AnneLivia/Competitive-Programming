#include <iostream>

using namespace std;

int main() {
    int k, x, y;
    cin >> k >> x >> y;
    if (k <= abs(x-y)) 
        cout << "EH SUFICIENTE\n";
    else
        cout << "NAO EH SUFICIENTE\n";
        
    return 0;  
}
