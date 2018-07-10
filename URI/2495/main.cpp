#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long int n, v;
    vector<bool>c;
    while(cin >> n) {
        c.clear();
        for(int i = 0; i < n; i++)
            c.push_back(false);
        for ( int i = 0; i < n - 1; i++) {
            cin >> v;
            c[v - 1] = true;
        }

        for( int i = 0; i < (int)c.size(); i++) {
            if(!c[i])
                cout << i + 1 << endl;
        }
    }

    return 0;
}
