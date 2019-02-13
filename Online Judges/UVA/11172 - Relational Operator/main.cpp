#include <iostream>

using namespace std;

int main()
{
    int t, n1, n2;
    cin >> t;
    while(t--) {
        cin >> n1 >> n2;
        if(n1 == n2)
            cout << "=\n";
        else if(n1 < n2)
            cout << "<\n";
        else
            cout << ">\n";
    }
    return 0;
}
