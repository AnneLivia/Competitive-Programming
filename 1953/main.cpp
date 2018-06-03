#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, nmat, epr, ehd, other;
    string disc;
    while(cin >> n) {
        epr = ehd = other = 0;
        while(n--) {
            cin >> nmat >> disc;
            if(disc.compare("EPR") == 0)
                epr++;
            else if (disc.compare("EHD") == 0)
                ehd++;
            else
                other++;
        }
        cout << "EPR: " << epr << endl;
        cout << "EHD: " << ehd << endl;
        cout << "INTRUSOS: " << other << endl;
    }
    return 0;
}
