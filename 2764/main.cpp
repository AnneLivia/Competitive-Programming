#include <iostream>

using namespace std;


int main()
{
    string c;
    cin >> c;
    cout << c[3] << c[4] << "/" << c[0] << c[1] << "/" << c[6] << c[7] << endl;
    cout << c[6] << c[7] << "/" << c[3] << c[4] << "/" << c[0] << c[1] << endl;
    cout << c[0] << c[1] << "-" << c[3] << c[4] << "-" << c[6] << c[7] << endl;
    return 0;
}
