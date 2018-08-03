#include <iostream>
#include <vector>

using namespace std;

vector<int>v, vis;
bool l, r;

void dfs(int pos, int jump) {
    v[pos] = 1;

    if((pos + jump) < (int)v.size() && !r) {
        dfs(pos+jump,jump);
    } else {
        r = true;
    }
    if((pos - jump) >= 0 && !vis[pos-jump] && !l) {
        dfs(pos-jump,jump);
    } else {
        l = true;
    }
}

int main()
{
    int qtdRocks, qtdFrogs, p, d, tam, i;

    cin >> qtdRocks >> qtdFrogs;

    v.assign(qtdRocks,0);
    vis.assign(qtdRocks,0);

    while(qtdFrogs--) {
        cin >> p >> d;
        r = l = false;
        dfs(p-1,d);
    }

    for(int i = 0; i < (int)v.size(); i++)
        cout << v[i] << endl;

    return 0;

}
