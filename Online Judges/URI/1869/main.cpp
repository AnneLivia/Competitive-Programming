#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long unsigned int n, aux;
    string s = "0123456789ABCDEFGHIJKLMNOPQRSTUV";
    string ans;

    while(true) {
        scanf("%llu",&n);
        ans = "";

        if(n == 0) {
            cout << "0\n";
            break;
        }

        while(n != 0) {
            aux = n % 32;
            ans+=s[aux];
            n/=32;
        }


        reverse(ans.begin(),ans.end());
        cout << ans << endl;
    }
    return 0;
}
