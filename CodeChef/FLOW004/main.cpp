#include <iostream>

using namespace std;

int main()
{
    string n;
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << ((n[0] - '0') + (n[n.size() - 1] - '0')) << endl;
    }
    return 0;
}
