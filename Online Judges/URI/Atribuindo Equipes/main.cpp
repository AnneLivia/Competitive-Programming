#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;

    cin >> a >> b >> c >> d;

    int op1 = abs((a+b) - (c+d));
    int op2 = abs((a+c) - (b+d));
    int op3 = abs((a+d) - (c+b));

    int m = min(op1,op2);
    m = min(op3, m);
    cout << m << endl;
    return 0;
}
