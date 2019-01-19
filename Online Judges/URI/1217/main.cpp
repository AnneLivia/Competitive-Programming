#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    int n, total_fruitsI, total_fruits, i = 1;
    float value, total_values;
    string fruits;
    total_values = total_fruits = total_fruitsI = 0;

    cin >> n;

    while(n--) {
        cin >> value;
        cin.ignore();
        getline(cin, fruits);

        stringstream split(fruits);
        string c;
        while(split >> c) {
            total_fruitsI++;
        }
        cout << "day " << i++ << ": " << total_fruitsI << " kg\n";
        total_fruits+=total_fruitsI;
        total_fruitsI = 0;
        total_values+=value;
    }

    cout.precision(2);
    cout.setf(ios::fixed);
    cout << (float) total_fruits / (i - 1) << " kg by day\n";
    cout << "R$ " << (float) total_values / (i - 1) << " by day\n";

    return 0;
}
