#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n, va, t;
    cin >> n >> t;
    set<int>s;
    while(t--) {
        cin >> va;
        s.insert(va);
    }

    cout << n - (int)s.size() << endl;
    return 0;
}
