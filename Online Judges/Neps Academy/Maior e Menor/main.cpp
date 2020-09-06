#include <iostream>

using namespace std;

int main()
{
    int n, na, me = 10000, ma = -1;
    cin >> n;

    while(n--) {
        cin >> na;
        if(na > ma)
            ma = na;
        if (na < me)
            me = na;
    }
    cout << ma << "\n" << me << endl;
    return 0;
}
