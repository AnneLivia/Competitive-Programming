#include <iostream>

using namespace std;

int main()
{
    int n, larger, t, i, cont3;
    string s;
    cin >> t;
    while(t--) {
        cin >> n;
        s = "";
        larger = 0;
        i = n + 1;
        while(!larger) {
            cont3 = 0;
            s = to_string(i);
            for(int j = 0; j < (int)s.size(); j++) {
                if(s[j] == '3')
                    cont3++;
            }
            if(cont3 >= 3)
                larger = i;
            i++;
        }
        cout << larger << endl;
    }
    return 0;
}
