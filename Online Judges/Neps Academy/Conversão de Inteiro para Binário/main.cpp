#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int x;
    cin >> x;
    string s = "";
    if (x == 0)
        cout << "0\n";
    else {
        while(x) {
            // checking if last bit is set
            if ((x & 1) == 0)
                s+="0";
            else
                s+="1";
            // shifting left
            x>>=1;
        }


        // reversing string, because in the loop it fill the string backwards
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    return 0;
}
