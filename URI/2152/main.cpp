#include <iostream>

using namespace std;

int main()
{
    int t,hour,minute,open;
    cin >> t;
    while(t--) {
        cin >> hour >> minute >> open;
        if(hour <= 9) {
            cout << 0 << hour << ":";
        } else {
            cout << hour << ":";
        }
        if(minute <= 9) {
            cout << 0 << minute << " - ";
        } else {
            cout << minute << " - ";
        }
        if(open)
            cout << "A porta abriu!\n";
        else
            cout << "A porta fechou!\n";
    }
    return 0;
}
