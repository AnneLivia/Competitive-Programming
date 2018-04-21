#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int np, n, s, t = 1;
    vector<int>v;
    while(cin >> np && np != 0) {
        v.clear();

        while(np--) {
            cin >> n;
            v.push_back(n);
        }
        s = 1;
        if(t != 1)
            cout << endl;
        for(int i = 0; i < (int)v.size(); i++) {
            if(i + 1 == v[i])
                s = i + 1;
        }

        cout << "Teste " << t++ << endl;
        cout << s << endl;
    }
    return 0;
}
