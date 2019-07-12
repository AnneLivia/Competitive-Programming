#include <iostream>

using namespace std;

int main()
{
    int A, B, C;
    int H, L;

    cin >> A >> B >> C;
    cin >> H >> L;

    if((A <= H && B <= L) || (A <= H && C <= L) ||
       (B <= H && A <= L) || (B <= H && C <= L) ||
       (C <= H && A <= L) || (C <= H && B <= L)) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }
    return 0;
}
