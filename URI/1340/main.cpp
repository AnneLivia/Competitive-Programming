#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    int t, op, n, q, s, pq, g, imp;
    vector<int>v;

    while(cin >> t) {
        q = s = pq = imp = 0;
        g = -1;
        v.clear();
        while(t--) {
            cin >> op >> n;
            if(op == 1) {
                v.push_back(n);
                if(g < n)
                    g = n;
            } else {
                if(!v.empty()) {
                    if(n == v[0])
                        q++;
                    if(n == v[(int)v.size() - 1])
                        s++;
                    if(n == g) {
                        pq++;
                        g = -1;
                        for (int i = 0; i < (int)v.size(); i++) {
                            if(g < v[i] && v[i] != n)
                                g = v[i];
                        }
                    }

                    if(find(v.begin(), v.end(), n) != v.end())
                        v.erase(find(v.begin(), v.end(), n), find(v.begin(), v.end(), n) + 1);
                    else
                        imp++;
                }
            }
        }
        if(imp > 0)
            cout << "impossible\n";
        else if (q > s && q > pq)
            cout << "queue\n";
        else if (s > pq)
            cout << "stack\n";
        else if (pq == s || pq == q)
            cout << "not sure\n";
        else
            cout << "priority queue\n";
    }
    return 0;
}
