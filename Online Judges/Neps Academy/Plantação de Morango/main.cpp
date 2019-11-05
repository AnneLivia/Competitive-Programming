#include <iostream>

using namespace std;

int main()
{
    int n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;
    int area1 = n1 * n2;
    int area2 = n3 * n4;

    cout << max(area1, area2) << endl;
    return 0;
}
