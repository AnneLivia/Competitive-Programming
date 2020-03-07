#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, t;
    
    cin >> n;

    set<int>s;

    for (int i = 0; i < n; i++) {
        cin >> t; 
        s.insert(t);
    }
    cout << (int)s.size() << endl;
    return 0;  
}
