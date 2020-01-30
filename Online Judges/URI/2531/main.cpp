#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Data {
    int minValue, maxValue;
};

ostream& operator << (ostream& ostr, const Data& d) {
    cout << "Max: " << d.maxValue << endl;
    cout << "Min: " << d.minValue << endl;
    return ostr;
}

// better than vector for optimization
int v[100001];
Data st[512345];

/*
    C++ provides an inline functions to reduce the function
    call overhead. Inline function is a function that is
    expanded in line when it is called. When the inline
    function is called whole code of the inline function
    gets inserted or substituted at the point of inline
    function call. This substitution is performed by the
    C++ compiler at compile time. Inline function may
    increase efficiency if it is small.
*/
inline int goLeft(int n) {return n << 1;}
inline int goRight(int n) {return (n << 1) + 1;}

void build(int n, int s, int e) {
    if (s == e) {
        st[n] = {v[s], v[s]};
    } else {
        int m = (s+e) >> 1;
        build(goLeft(n), s, m);
        build(goRight(n), m + 1, e);

        // save min value and also save max value in next node (they are gonna be used next)
        st[n].minValue = min(st[goLeft(n)].minValue, st[goRight(n)].minValue);
        st[n].maxValue = max(st[goLeft(n)].maxValue, st[goRight(n)].maxValue);
    }
}

void update(int n, int s, int e, int i, int a) {
    if (s == e) {
        st[n] = {a,a};
        v[i] = a;
    } else {
        int m = (s + e) >> 1;
        if (i <= m) {
            update(goLeft(n), s, m, i, a);
        } else {
            update(goRight(n), m + 1, e, i, a);
        }

        st[n].minValue = min(st[goLeft(n)].minValue, st[goRight(n)].minValue);
        st[n].maxValue = max(st[goLeft(n)].maxValue, st[goRight(n)].maxValue);
    }
}

Data query(int n, int s, int e, int i, int j) {
    if (s > j || e < i)
        return {0x3f3f3f3f,-0x3f3f3f3f}; // very large number, similar to infinity
    else if (i <= s && e <= j) {
        // completely inside
        return st[n];
    }

    // using that large number above, they are not going to influence min and max
    // since they are very large
    // partially in range i - j
    int m = (s + e) >> 1;

    Data l = query(goLeft(n), s, m, i, j);
    Data r = query(goRight(n), m + 1, e, i, j);

    // the only interesting value is the max difference,
    //  return max and min value in a range
    return {min(l.minValue, r.minValue), max(l.maxValue, r.maxValue)};
}

int main() {
    // scanf and printf are better that cin and cout even using tie
    int n, q, a, b, op;

    while(scanf("%d", &n) != EOF) {

        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }

        build(1, 0, n - 1);

        scanf("%d", &q);

        while(q--) {
            scanf("%d %d %d", &op, &a, &b);
            if(op == 1) {
                update(1, 0, n - 1, a - 1, b);
            } else {
                Data d = query(1, 0, n - 1, a - 1, b - 1);
                printf("%d\n",abs(d.maxValue - d.minValue));
            }
        }
    }
    return 0;
}
