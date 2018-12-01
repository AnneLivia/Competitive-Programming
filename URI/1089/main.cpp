#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t, des, pic;
    vector<int>v;
    while(cin >> t && t) {
        v.assign(t + 2, 0);

        for (int i = 0; i < t; i++) {
            cin >> v[i];
        }
        v[t] = v[0];
        v[t + 1] = v[1];
        des = v[0] > v[1];
        pic = 0;
        for (int i = 0; i < t + 1; i++) {
            if((des && !(v[i] > v[i + 1])) || (!des && (v[i] > v[i + 1]))) {
                pic++;
                des = (v[i] > v[i + 1]);
            }
        }
        cout << pic << endl;
    }
    return 0;
}
