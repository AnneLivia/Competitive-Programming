#include <iostream>

using namespace std;

int main()
{
    int n;
    double value = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        value+=2.0;
        value = 1.0/value;
    }
    value+=1.0;
    cout.precision(10);
    cout.setf(ios::fixed);
    cout << value << endl;
    return 0;
}
