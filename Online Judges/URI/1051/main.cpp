#include <iostream>

using namespace std;

int main()
{
    double cash;
    cin >> cash;
    cout.precision(2);
    cout.setf(ios::fixed);
    if(cash >= 0.0 && cash <= 2000.00) {
        cout << "Isento\n";
    } else if(cash >= 2000.01 && cash <= 3000.00) {
        cout << "R$ " << (cash - 2000) * 0.08 << endl;
    } else if (cash >= 3000.01 && cash <= 4500.00) {
        double ex1;
        ex1 = (((cash - 3000) * 0.18) + (1000 * 0.08));
        cout << "R$ " << ex1 << endl;
    } else {
        double ex1;
        ex1 = (((cash - 4500) * 0.28) + ((4500 - 3000) * 0.18) + ((3000 - 2000) * 0.08));
        cout << "R$ " << ex1 << endl;
    }
    return 0;
}
