#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t, s[3], x = 1;

    cin >> t;
    while(t--) {
        cin >> s[0] >> s[1] >> s[2];
        sort(s,s+3);
        cout << "Case " << x++ << ": " << s[1] << endl;
    }
    return 0;
}
