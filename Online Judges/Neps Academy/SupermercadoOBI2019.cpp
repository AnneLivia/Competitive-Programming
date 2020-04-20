#include <iostream>

using namespace std;

int main() {
    int n, grama;
    double value, min = 10000000.0, resp;
    cin >> n;
    while(n--) {
        cin >> value >> grama;
        resp = (1000.00 / grama) * value;
        if (resp < min) 
            min = resp;
    }    
    cout.precision(2);
    cout.setf(ios::fixed);
    cout << min << endl;
    return 0;  
}
