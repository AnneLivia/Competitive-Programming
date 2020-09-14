#include <iostream>

using namespace std;

int main() {
    int n, pa = 0, va = 7;
    cin >> n;
    while(n >= 101) {
        va+=5;
        n-=1;
    }
    while(n >= 31 && n <= 100) {
        va+=2;
        n-=1;
    }
    while(n >= 11 && n <= 30) {
        va+=1;
        n-=1;
    }
    cout << va << endl;
    return 0;  
}
