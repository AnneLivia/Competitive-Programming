#include <iostream>
#include <vector>
#include <stack>

using namespace std;
typedef vector<int>vi;

vi id;

int detect(int p) {
    if(id[p] == p)
        return p;
    return id[p] = detect(id[p]);
}

void unify(int x, int y) {
    x = detect(x);
    y = detect(y);

    id[x] = y;
}

int main()
{
    int n, e, x, y, components, cycle = false;
    cin >> n >> e;
    components = n;
    id.assign(n, 0);
    for (int i = 0; i < n; i++)
        id[i] = i;
    for (int i = 0; i < e; i++) {
        cin >> x >> y;
        if(detect(x - 1) != detect(y - 1)) {
            unify(x - 1,y - 1);
            components--;
        } else {
            cycle = 1;
            break;
        }
    }
    /*
          a
         / "\" -> this won't happen, so always for a tree the number of edges is number of nodes - 1
        b
      /  \
     c    d
        /
       e
    */
    // number of nodes - 1 is equal to number of edge
    // check if there's only one component and there's no cycle
    if(n - 1 == e && components == 1 && !cycle) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
