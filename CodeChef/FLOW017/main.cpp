#include <iostream>

using namespace std;

int main()
{
    int t, n1, n2, n3;
    cin >> t;
    while(t--) {
        cin >> n1 >> n2 >> n3;
        if(n1 > n2 && n1 > n3 && n2 > n3)
            cout << n2 << endl;
        else if(n1 > n2 && n1 > n3 && n3 > n2)
            cout << n3 << endl;
        else if(n2 > n1 && n2 > n3 && n1 > n3)
            cout << n1 << endl;
        else if(n2 > n1 && n2 > n3 && n3 > n1)
            cout << n3 << endl;
        else if(n3 > n1 && n3 > n2 && n1 > n2)
            cout << n1 << endl;
        else if(n3 > n1 && n3 > n2 && n2 > n1)
            cout << n2 << endl;
    }
    return 0;
}
