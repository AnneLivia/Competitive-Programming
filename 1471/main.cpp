#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,r,s,c;
    vector<bool>v;
    bool flag;
    while( cin >> n >> r ) {
        c = 0;
        v.clear();
        flag = false;
        for(int i = 0; i < n; i++) {
            v.push_back(false);
        }

        while(r--) {
            cin >> s;
            v[s - 1] = true;
        }

        for(int i = 0; i < (int)v.size(); i++) {
            if(!v[i]) {
                cout << i + 1 << " ";
            } else {
                c++;
            }
        }
        if(c == (int)v.size())
            cout << "*" << endl;
        else
            cout << endl;
    }
    return 0;
}
