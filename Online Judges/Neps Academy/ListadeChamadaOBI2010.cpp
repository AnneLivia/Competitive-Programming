#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<string>s(n, "");
    for (int i = 0; i < n; i++) {
         cin >> s[i];
    }
    sort(s.begin(), s.end());
    cout << s[t-1] << endl;
    
    return 0;  
}
