#include <iostream>
#include <vector>

using namespace std;

/*
    1583 - Contaminação URI
*/

vector<vector<char> >v;
vector<vector<int> >vi;
int n, m;

void dfs(int i, int j) {
    if(!vi[i][j]) {
        vi[i][j] = 1;
        v[i][j] = 'T';
        if(i + 1 < n && (v[i + 1][j] == 'A' || v[i + 1][j] == 'T') && !vi[i + 1][j])
            dfs(i + 1, j);
        if(i - 1 >= 0 && (v[i - 1][j] == 'A' || v[i - 1][j] == 'T') && !vi[i - 1][j])
            dfs(i - 1, j);
        if(j + 1 < m && (v[i][j + 1] == 'A' || v[i][j + 1] == 'T') && !vi[i][j + 1])
            dfs(i, j + 1);
        if(j - 1 >= 0 && (v[i][j - 1] == 'A' || v[i][j - 1] == 'T') && !vi[i][j - 1])
            dfs(i, j - 1);
    }
}

ostream& operator << (ostream& stream, vector<vector<char>>&v) {
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            stream << v[i][j];
        }
        stream << endl;
    }
    return stream;
}

int main()
{
    char c;
    while(cin >> n >> m && n && m) {
        v.assign(n, vector<char>());
        vi.assign(n, vector<int>());
        for (int i = 0; i < n; i++) {
            vi[i].resize(m);
            for(int j = 0; j < m; j++) {
                cin >> c;
                v[i].push_back(c);
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(v[i][j] == 'T' && !vi[i][j]) {
                    dfs(i,j);
                }
            }
        }

        cout << v << "\n";
    }
    return 0;
}
