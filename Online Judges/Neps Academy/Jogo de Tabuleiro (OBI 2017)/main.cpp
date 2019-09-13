#include <iostream>
#include <vector>

using namespace std;

ostream& operator << (ostream& stream, const vector<vector<int> >& v) {
    for (auto i : v) {
        for (auto j : i) {
            stream << j << " ";
        }
        stream << "\n";
    }
    return stream;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int> > v(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            int p = 0, b = 0;
            v[i - 1][j] == 0 ? b++ : p++;
            v[i][j - 1] == 0 ? b++ : p++;
            v[i - 1][j - 1] == 0 ? b++ : p++;
            v[i][j] = b > p ? 1 :  0;
        }
    }

    cout << v[n - 1][n - 1] << endl;
    return 0;
}
