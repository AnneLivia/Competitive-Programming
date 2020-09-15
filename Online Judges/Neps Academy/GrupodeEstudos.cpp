#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int>ma;
    int n, va;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> va;
        ma.insert(va);
    }
    
    cout << (int)ma.size() << endl;
    return 0;  
}
