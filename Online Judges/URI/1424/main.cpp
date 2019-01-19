#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, nc, x, cont, y;
    vector<int>v;
    while(cin >> n >> nc) {
        v.clear();
        while(n--) {
            cin >> x;
            v.push_back(x);
        }

        while(nc--) {
            cont = 0;
            cin >> x >> y;
            for(int i = 0; i < (int)v.size(); i++) {
                if(v[i] == y) {
                    cont++;
                }

                if(cont == x)  {
                    cout << i + 1 << endl;
                    break;
                }
            }

            if(cont != x)
                cout << 0 << endl;
        }
    }
    return 0;
}
