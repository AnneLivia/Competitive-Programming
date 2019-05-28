#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

vector<int>id, sz;

int detect(int p) {
    if(p == id[p])
        return p;
    return id[p] = detect(id[p]);
}

void unify(int p, int q) {
    p = detect(p);
    q = detect(q);
    if(sz[p] > sz[q])
        swap(p,q);
    id[p] = q;
    sz[q]+=sz[p];
}

int main()
{
    int n, m, q, x, y, fs = 1;

    while(scanf("%d %d %d", &n, &m, &q) != EOF) {
        id.assign(n, 0);
        sz.assign(n, 1);

        if(!fs)
            printf("\n");

        for(int i = 0; i < n; i++)
            id[i] = i;
        while(m--) {
            scanf("%d %d", &x,&y);
            if(detect(x - 1) != detect(y - 1))
                unify(x - 1, y - 1);
        }

        while(q--) {
            scanf("%d %d", &x,&y);
            if(detect(x - 1) == detect(y - 1))
                printf("S\n");
            else
                printf("N\n");
        }

        fs = 0;
    }
    return 0;
}
