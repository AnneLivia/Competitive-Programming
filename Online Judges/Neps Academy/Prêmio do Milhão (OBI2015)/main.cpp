#include <iostream>

using namespace std;

int main()
{
    int n, a, s = 0, t = 0, flag = 0;
    cin >> n;
    while(n--) {
        cin >> a;
        s+=a;
        if(!flag) {
            t++;
        }

        if(s >= 1000000)
            flag = 1;
    }

    cout << t << endl;
    return 0;
}
