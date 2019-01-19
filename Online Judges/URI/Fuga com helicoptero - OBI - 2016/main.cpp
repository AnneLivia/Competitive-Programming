#include <iostream>

using namespace std;

int main()
{
    int police, thief, helicopter, hour_orientation;
    bool getToH, getToP;
    getToP = getToH = false;
    cin >> helicopter >> police >> thief >> hour_orientation;

    while(true) {
        if(hour_orientation == -1) {
           thief--;
           if(thief == -1)
             thief = 15;
        } else {
           thief++;
           if (thief == 16)
             thief = 0;
        }
        if(thief == helicopter)
            getToH = true;
        if(thief == police) {
            getToP = true;
        }

        if(getToH || getToP)
            break;

    }

    if(getToH && !getToP)
        cout << "S\n";
    else
        cout << "N\n";

    return 0;
}
