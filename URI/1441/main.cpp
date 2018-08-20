#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int hn, n = -1, i;
    vector<long int>v;
    while(cin >> hn && hn) {
        v.clear();
        v.push_back(hn);
        i = 1;
        n = v[i - 1];
        while(n != 1) {

            if(v[i - 1] % 2 == 0) {
                v.push_back(v[i - 1]/2);
            } else {
                v.push_back(3 * v[i - 1] + 1);
            }

            i++;

            n = v[i - 1];
        }


       sort(v.begin(),v.end());
       cout << v[((int)v.size() - 1)] << endl;
    }
    return 0;
}
