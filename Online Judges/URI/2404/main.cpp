#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Road {
    int city1, city2, distance;
};

class Map {
    vector<Road>c;
    vector<int>id, sz;
    int nCities;
public:
    Map(int nCities) : nCities(nCities) {
        sz.assign(nCities + 1, 1);
        id.assign(nCities + 1, 0);
        for (int i = 0; i < nCities + 1; i++) {
            id[i] = i;
        }
    }

    void add_road(int city1, int city2, int distance) {
        c.push_back({city1, city2, distance});
    }

    int detect(int p) {
        if(id[p] == p)
            return p;
        return id[p] = detect(id[p]);
    }

    void unify(int p, int q) {
        int rootp = detect(p);
        int rootq = detect(q);

        if(rootp == rootq)
            return;

        if(sz[rootp] > sz[rootq])
            swap(q,p);

        id[rootp] = id[rootq];
        sz[rootq]+=sz[rootp];
    }

    int kruskal() {
        int sum = 0;
        vector<Road>tree;
        sort(c.begin(), c.end(), [](const Road& r1, const Road& r2) {
            return r1.distance < r2.distance;
        });
        for (int i = 0; i < (int)c.size(); i++) {
            int c1 = c[i].city1;
            int c2 = c[i].city2;
            if(detect(c1) != detect(c2)) {
                unify(c1, c2);
                tree.push_back(c[i]);
                sum+=c[i].distance;
            }
        }
        return sum;
    }
};
int main()
{
    int ncity, nroad, city1, city2, distance, cont = 0;

    cin >> ncity >> nroad;

    Map m(ncity);

    while(nroad--) {
        cin >> city1 >> city2 >> distance;
        m.add_road(city1, city2, distance);
    }

    cout << m.kruskal() << endl;

    return 0;
}
