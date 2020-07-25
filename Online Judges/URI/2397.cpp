#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    if ((b + c) > a && (a + c) > b && (b + a) > c) {
        float angleA = acos((b * b + c * c - a * a) / ( 2.0 * b * c));
        float angleB = acos((a * a + c * c - b * b) / ( 2.0 * a * c));
        float angleC = acos((a * a + b * b - c * c) / ( 2.0 * b * a));

        // converting to degree
        angleA = (int)(angleA * 180 / 3.1415);
        angleB = (int)(angleB * 180 / 3.1415);
        angleC = (int)(angleC * 180 / 3.1415);

        if (angleA == 90 || angleB == 90 || angleC == 90) {
            cout << "r\n";
        } else if (angleA < 90 && angleB < 90 && angleC < 90) {
            cout << "a\n";
        } else {
            cout << "o\n";
        }
    } else {
        cout << "n\n";
    } 
    return 0;  
}
