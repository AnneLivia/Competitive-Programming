#include <iostream>
#include <vector>

using namespace std;

/*
    Segment tree allows to perform operations such as:
        find something in a interval a..b in O(log n)
        update some value in position a O(Log n)
    but if I want to update all value in a interval a..b,
    the complexity here is going to be O(n log n), since
    I'm going to have to call the function update to all value
    in the range a b.
    This is not a good complexity for some problems in competitive programming
    hence, to update this, we use the lazy propagation adaptation, that allows
    to perform both operations in O (log N).

    The intuition behind the lazy propagation is:
        instead of update all node (including all of its children)
        we wait and only update a node when we're gonna need the information
        in that node. When we in fact need to use the information in some node
        we then perform all of the delayed operations and pass the information to all of its child
*/

int st[8] = {0}, a[4] = {1,2,3,4};

int goleft(int n) {return n << 1;}
int goright(int n) {return (n << 1) + 1;}
// build is the same as a trivial segment tree
void build(int n, int s, int e) {
    if (s == e)
        st[n] = a[s];
    else {
        int m = (s + e) >> 1;
        build(goleft(n), s, m);
        build(goright(n), m + 1, e);

        st[n] = st[goleft(n)] + st[goright(n)];
    }
}

// function to update single value
void update(int n, int s, int e, int i, int v) {
    if (s == e) {
        st[n] = v;
        a[i] = v;
    } else {
        int m = (s + e) >> 1;
        if (m <= i) {
            update(goleft(n), s, m, i, v);
        } else {
            update(goright(n), m + 1, e, i, v);
        }

        st[n] = st[goleft(n)] + st[goright(n)];
    }
}

// To avoid multiple call to update function,
// we can modify the update function to work on an interval.
void updateRange(int n, int s, int e, int i, int j, int v, string space="") {
    cout << space << "Node " << n << " -> range (" << i << ", " << j << ")\n";
    cout << space << "Start and end of node " << n << ": " << s << " - " << e << endl;
    // if the value is out of range, just return
    if (s > j || e < i) {
        cout << space << "Out of range\n";
        return;
    }

    // if it's leaf
    if (s == e) {
        // add value to the current node
        cout << space << "updating leaf " << n << endl;
        st[n]=v;
        a[s]=v;
        return;
    }

    // if it's not a leaf node, need to go to left and right
    int m = (s + e) >> 1;
    updateRange(goleft(n), s, m, i, j, v,space+=" ");
    updateRange(goright(n), m + 1, e, i, j, v, space+=" ");
    // use the result to update nodes
    st[n] = st[goleft(n)] + st[goright(n)];
}

// lazy array must have the same size as the segment tree
int lazy[8] = {0};
// Initially all the elements of the lazy[]
// array will be 0 representing that there is no pending update.
// If there is non-zero element lazy[k] then this element needs to update node
// k in the segment tree before making any query operation.

/*
    To update an interval we will keep 3 things in mind.

    1. If current segment tree node has any pending update,
    then first add that pending update to current node.

    2. If the interval represented by current node lies
    completely in the interval to update, then update
    the current node and update the lazy[] array for
    children nodes (only the lazy array).

    3. If the interval represented by current node overlaps
    with the interval to update, then update the nodes
    as the earlier update function

    Since we have changed the update function to postpone
    the update operation, we will have to change the query
    function also. The only change we need to make is to
    check if there is any pending update operation on that node.
    If there is a pending update operation, first update the
    node and then work same as the earlier query function.
*/

// the first thing we need to check when using lazy is if there's pending value
// after that we can continue normally with the function
// when updating, if the node is not a leaf, it means it's child must be updated to
// so with end - start + 1, we get the number of nodes we need to update, multiply by the value
// and then update lazy of left and right to value passed as argument to the function

void updateRangeLazy(int n, int s, int e, int i, int j, int v) {
  // verify if the current node is different from 0 in lazy, if it is,
  // then I need to update it accordingly to the value in lazy
  if (lazy[n]) {
    // update the value in st
    // e - s + 1 is used to update value in node s - e + 1 times since the
    // update occurs from i to j.
    // suppose I want to update the value from 1 to 1, 1 - 1 + 1 is 1, so update one value only
    // suppose it was, 1 to 3, 3 - 1 + 1 = 3, three number were change, need update it
    st[n] = (e - s + 1) * lazy[n]; // updating it.

    // after it need to update the lazy of the children of the
    // current node, if the current node is not a leaf with the value in lazy[no]
    if (s != e) {
        lazy[goleft(n)] =lazy[n];
        lazy[goright(n)] =lazy[n];
    }

    // since current node was updated, assign 0 to lazy
    // there's no more pending update
    lazy[n] = 0;
  }

  // after updating value if needed, it's time to check the ranges
  if (s > e || s > j || e < i)
    return; // out of range

  // j - i + 1 gives number of nodes cover by some node (range)
  if (i <= s && e <= j) {
    // completely in range
    st[n] = v*(e - s + 1); // update value (j - i + 1 times)

    // if is not a leaf, update value in lazy of its child
    if (s != e) {
        lazy[goleft(n)] = v;
        lazy[goright(n)] = v;
    }
  } else {
    // partially in range
    // call both child and update value
    int m = (s + e) >> 1;
    updateRangeLazy(goleft(n), s, m, i, j, v);
    updateRangeLazy(goright(n), m+1, e, i, j, v);

    // must update parent
    st[n] = st[goleft(n)] + st[goright(n)];
  }
}

int query(int n, int s, int e, int i, int j) {
    if (s > j || e < i)
        return 0;
    if (i <= s && e <= j) {
        return st[n];
    }

    int m = (s + e) >> 1;
    // partially
    int n1 = query(goleft(n), s, m, i, j);
    int n2 = query(goright(n), m + 1, e, i, j);

    return n1 + n2;
}

// query with lazy
int query_lazy(int n, int s, int e, int i, int j) {
    // check if there's pending value
    if (lazy[n]) {
        // update it (e - s + 1) times (number of nodes that were changed
        st[n] = lazy[n] * (e - s + 1);
        // check if is not a leaf, if it is, then add lazy to its child
        if (s != e) {
            lazy[goleft(n)] = lazy[n];
            lazy[goright(n)] = lazy[n];
        }

        lazy[n] = 0; // nulling the value in lazy n, because the value value was updated
    }

    // now, after the proper update, query the values
    // check if it's out of range
    if (s > e || s > j || e < i)
        return 0;
    // check if it's completely in range
    if (i <= s && e <= j) {
        return st[n];
    } else {
        int m = (s + e) >> 1;
        // partially in range, go left and right and return sum of its value
        int l = query_lazy(goleft(n), s, m, i, j);
        int r = query_lazy(goright(n), m + 1, e, i, j);

        return l + r;
    }
}

int main()
{
    build(1, 0, 3);
    cout << "Before\n";
    for (int i = 0; i < 8; i++) {
        cout << "[" << i << "] = " << st[i] << endl;
    }
    cout << "\n\nAfter\n";
    updateRangeLazy(1, 0, 3, 1, 3, 2);
    for (int i = 0; i < 8; i++) {
        cout << "[" << i << "] = " << st[i] << endl;
    }
    cout << query_lazy(1, 0, 3, 1, 2) << endl;
    // since the query here required a value that need to be updated
    // the function does those update
    cout << "\n\nAfter lazy query\n";
    for (int i = 0; i < 8; i++) {
        cout << "[" << i << "] = " << st[i] << endl;
    }
    return 0;
}
