#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t, found;
    float n1, n2;
    vector<float>v;
    while(cin >> t) {
        v.clear();
        for(int i = 1; i <= t; i++){
           cin >> n1 >> n2;
           v.push_back(n2/n1);
        }

        cout << 1 << endl;
        for(int i = 1; i < (int)v.size(); i++) {
            found = 0;
            for(int j = 0; j < i; j++) {
                if(v[i] <= v[j]) {
                    found = 1;
                    break;
                }
            }

            if(!found)
                cout << i + 1 << endl;
        }
    }
    return 0;
}
