#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    vector<long long int> v;
    set<long long int>s;
    int t, cont;
    long long int n;
    while(cin >> t && t != 0){
        v.clear();
        s.clear();

        for(int i = 0; i < t ; i++) {
            cin >> n;
            v.push_back(n);
        }

        sort(v.begin(),v.end());
        v.push_back(v.back() + 1);

        for ( int i = 0; i < t;) {
            if(v[i] == v[i + 1])
                i+=2;
            else {
                s.insert(v[i]);
                i++;
            }
        }
        for ( auto it = s.begin(); it != s.end(); it++) {
            if(it != s.begin())
                cout << " ";
            cout << *it;
        }
        cout << endl;


    }
    return 0;
}
