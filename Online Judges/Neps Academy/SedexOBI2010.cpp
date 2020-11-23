#include <iostream>

using namespace std;

int main() {
    int n, l, h, c;
    cin >> n >> l >> h >> c;
    if (l >= n && h >= n && c >= n) 
        cout << "S\n";
    else 
        cout << "N\n";    
    return 0;  
}
