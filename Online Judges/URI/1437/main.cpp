#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int d, pos;
    string ins;
    while(cin >> d && d) {
        pos = 0;
        cin >> ins;
        for ( int i = 0; i < d; i++) {

            if(ins[i] == 'D') {
                pos++;
                if(pos == 4)
                    pos = 0;
            } else {
                pos--;
                if(pos == -1)
                    pos = 3;
            }
        }

        if(pos == 0)
            cout << "N\n";
        else if (pos == 1)
            cout << "L\n";
        else if (pos == 2)
            cout << "S\n";
        else
            cout << "O\n";
    }
    return 0;
}
