#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int minute, brasil, germany;
    while(true) {
        cin >> minute;
        if(!minute)
            break;
        brasil = floor((double(minute/90.0)) * 1);
        germany = ceil(7 * ((double)(minute/90.0)));
        cout << "Brasil " << brasil << " x Alemanha " << germany << endl;
    }
    return 0;
}
