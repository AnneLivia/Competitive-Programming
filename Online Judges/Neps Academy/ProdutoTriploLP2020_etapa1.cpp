#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    long long int mult = 1LL, c;
    int n;

    cin >> n;
    
    long long int v[n+1];
    
    for (int i = n - 1; i >= 0; i--) {
        cin >> v[i];
    }

    mult = max(v[0] * v[1] * v[2], v[0] * v[n - 1] * v[n - 2]);
    
    cout << mult << endl;
    return 0;  
}
