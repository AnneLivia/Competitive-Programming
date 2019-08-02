#include <iostream>
#include <vector>

using namespace std;

ostream& operator << (ostream& ostr, const vector<int>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        if( i != 0)
            ostr << " ";
        ostr << v[i];
    }
    return ostr;
}

int main()
{
    int n;
    cin >> n;
    vector<int>v(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int is_0 = -2, is_5 = -2;

    if(v[n - 1] != 0 && v[n - 1] != 5) {
        is_0 = -1, is_5 = -1;
        for (int i = 0, j = n - 1; i < n && j >= 0; i++, j--) {
            if(v[i] == 0) {
                is_0 = i;
                break;
            } else if (v[i] == 5 && v[n - 1] > v[i]) {
                is_5 = i;
                break;
            }

            if(is_5 == -1 && v[j] == 5) {
                is_5 = j;
            }
        }
    }

    if(is_0 != -1 && is_0 != -2) {
        swap(v[is_0], v[n - 1]);
    } else if (is_5 != -1 && is_5 != -2) {
        swap(v[is_5], v[n - 1]);
    }

    if(is_0 == -1 && is_5 == -1)
        cout << -1 << endl;
    else
        cout << v << endl;
    return 0;
}
