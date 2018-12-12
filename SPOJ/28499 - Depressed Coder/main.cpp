#include <iostream>

using namespace std;

int main()
{
    int t, ct, hct, lab, tlab, atclass, total;
    cin >> t;
    while(t--) {
        cin >> ct >> lab >> hct >> tlab >> atclass;
        total = (ct * hct) + (lab * tlab) + atclass + 10;
        if(24 - total >= 3) {
            cout << "Khushi\n";
        } else {
            cout << "Hotash\n";
        }
    }
    return 0;
}
