#include <iostream>

using namespace std;

int main() {
    int n, a, b;
    long long int to = 0;
    cin >> n;
    while(n--) {
        cin >> a >> b;
        to+=a*b;
    }
    cout << to << endl;
    return 0;  
}
