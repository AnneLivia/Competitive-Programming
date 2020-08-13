#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    // a - competitors number, b - number of papers, c - number of paper each competitor must receive
    cin >> a >> b >> c;
    if ((c * a) > b) {
        cout << "N\n";
    } else {
        cout << "S\n";
    }
    return 0;  
}
