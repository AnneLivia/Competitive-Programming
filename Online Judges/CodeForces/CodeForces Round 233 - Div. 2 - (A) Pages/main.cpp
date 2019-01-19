#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, p, k;
    cin >> n >> p >> k;

    if(p - k > 1) {
        cout << "<< ";
    }

    int start = p - k <= 0 ? 1 : p - k;

    for(int i = start; i <= p + k && i <= n; i++) {
        if(i != start)
            cout << " ";
        if(i == p)
            cout << "(" << i << ")";
        else
            cout << i;
    }
    if(p + k < n)
        cout << " >>\n";
    return 0;
}
