#include <iostream>
#include <vector>

/*
    Segment Tree is a versatile data structure.
    that can perform many operations such as:
    sum in a range, update in a range, minimum/maximum in a range
    in O(log n).

    The difference of segment tree to Fenwick tree (BIT):
    BIT is better for accumulated sum (it simplifies the prefix sum - cumulative sums)
    where  we can obtain a sum in a specific range in O(log n).
    ST can do what BIT does and much more.

    Anything that can be done using a BIT can also be done using a segment tree :
    BIT stores cumulative quantities for certain intervals.
    Segment tree stores cumulative quantities for those intervals and more.

    Fenwick Tree (or BIT - Binary Indexed Tree) is less powerful
    than Segment Tree - it can only calculate prefix sums,
    while Segment Tree can calculate sums on any subsegment.

    Construction:
        - A ST must have a 2*n size array, ignoring index 0;
        - child of index x:
            - 2x and 2x+1.
        parent of x:
            - x/2;

    FROM HackEarth: https://www.hackerearth.com/pt-br/practice/notes/segment-tree-and-lazy-propagation/
    Segment tree is a binary tree used for storing the intervals or segments.
    Each node in the segment tree represents an interval.

    Consider an Array A of size N and a corresponding ST TT
        - The root of this tree is going to store the whole interval A[0..N-1]
        - Each one of the leafs are going to represent a single value in A[i] such that 0 <= i < n.
        - The internal nodes in the TT represents the union of elementary intervals A[i:j]
        where 0 <= i < j < N.
    The root is going to represent the whole array
    then we need to break the array into half, such that the two children of root is:
        - A[0 ... ((N - 1)/2)) and A[(((n+1)/2) + 1) ... N - 1).
    So in each step we will divide the interval into half
    and the two children will represent the two halves.
    The height of the segment tree will be log2N.
    There are N leaves representing the N elements of the array.
    The number of internal nodes is N-1.
    The total number of nodes are 2*N - 1.

    the structure of the ST is static, once its build cannot be destructed
    It's possible update the values of nodes but we cannot change its structure

    Segment tree provides two operations:
        - Update: In this operation we can update an element in the Array
           and reflect the corresponding change in the Segment tree.
        - Query: In this operation we can query on an interval
           or segment and return the answer to the problem on that particular interval.

    Since a ST is a binary tree, we can use a simple linear array to represent the segment tree.

    We need to know what we need to store in a ST, for example:
        - if we need to get the minimum number in a range, then we store the minimum of its children nodes
        - if we need to get the sum, we store in each node the sum of its children nodes.
        etc.
    Once we know what we need to store in the segment tree we can build the tree using recursion ( bottom-up approach ).
    --- We will start with the leaves and go up to the root and update the corresponding changes in
    the nodes that are in the path from leaves to root. Leaves represent a single element.
    In each step we will merge two children to form an internal node.
    Each internal node will represent a union of its Children's intervals.
    Merging may be different for different problems.
    So, recursion will end up at root which will represent the whole array.

    -- For update, we simply have to search the leaf that contains the element to update.
    -- This can be done by going to either on the left child or the right child depending
    -- on the interval which contains the element. Once we found the leaf,
    -- we will update it and again use the bottom-up approach to update
    -- the corresponding change in the path from leaf to root.

    -- To make a query on the segment tree we will be given a range from l to r.
    -- We will recurse on the tree starting from the root and check if the interval
    -- represented by the node is completely in the range from l to r. If the interval
    -- represented by a node is completely in the range from l to r, we will return that node's value.

    Naive approach:
        -- Use a simple array and run through interval i..j, complexity O(n);
            Update a value, complexity O(1). (this approach is good when we
            perform more updates and less query.)
        -- Use a prefix table: each query store the sum of previous one, to get sum
            we do sum[j]- sum[j - 1], complexity o(1), but to update, the complexity is going to be O(n),
            (this approach is good when we perform many query and few updates.

    ST for sum: We will build a segment tree using recursion ( bottom-up approach ) as explained above. Each leaf will have a single element.
    All the internal nodes will have the sum of both of its children.

*/

using namespace std;

class SegmentTree {
    vector<int>st;
    int tam;
public:
    vector<int>a;
    SegmentTree(vector<int>& aa) {
        tam = (int)aa.size();
        st.assign(tam * 2, 0);
        a = aa;
    }

    // ini and fim represents the interval represented by the node. Complexity of build() is O(N).
    void constructST (int no, int ini, int fim) {
        // it means we've found a leaf
        if(ini == fim) {
            st[no] = a[ini];
        } else {
            // need to run through tree and store sum in each interval (segment)
            // need to get middle element so that we can split array into half
            int middle = (ini + fim) >> 1;  // could be divide by 2 (same as >> 1).

            // recursively on the left (to access left child 2 * node)
            constructST(2*no, ini, middle);

            // recursively on the right (to access right child 2 * node + 1
            constructST(2*no + 1, middle + 1, fim);

            // internal node has the sum of its two children (left and right)
            // when it gets here, the sum is going to be there in both nodes
            st[no] = st[2*no] + st[2 * no + 1];
        }

        /*
            Simulation:
            A = {1,2,3,4,5,6}
            no = 1, ini = 0 and fim = 5.
            ini(0) == fim(1) ? no
            then: middle = (ini + fim) / 2 = 2
                - go left (2 * no(1), ini(0), fim = middle(2)
                -  ini(0) == fim(2)? no
                then: middle = (ini + fim) / 2 = 1
                    - go left (2*no(2), ini(0), middle(1))
                    - ini(0) == middle(1)? no
                    then: middle = (ini + fim) / 2 = 0
                        - go left (2*no(4), ini(0), middle(0))
                        - ini(0) == middle(0) ? yes, then: st[no(8)] = a[ini(0)](1)
                          return ...
                        - go right (2*no(4) + 1, ini = middle + 1 = 1, fim(1));
                        - ini(1) == middle(1)? yes, then: st[no(9)] = a[ini](2)
                          return ...
                        st[no(4)] = st[2*no(4)](1) + st[2*no(4) + 1](2);
                        ...
                    ...
                ...
            ...
            and it keep on going.
        */
    }

    // To update an element we need to look at the interval in which the element is and recurse accordingly
    // on the left or the right child.
    // no - node of st, ini and fim are the interval, index it's the index i want to update and val is the value to assign
    // Complexity of update will be O(logN).
    void updatevalue(int no, int ini, int fim, int index, int val) {
        // all single values are store in leaf node
        if(ini == fim) {
            // if it got here, found the leaf where index is
            // update array and st
            a[index]=val;
            st[no]=val;
        } else {
            // need to check where index is (left or right)
            int mid = (ini + fim) >> 1;
            if(index >= ini && index <= mid) {
                // if it got here, it's in the left
                // call left side again until find its leaf
                updatevalue(2*no, ini, mid, index, val);
            } else {
                // if it got here, it's in the right
                // call right side again until find its leaf
                updatevalue(2*no + 1, mid + 1, fim, index, val);
            }

            // after find its leaf, need to update tree
            st[no] = st[no*2] + st[no*2+1];
        }
    }

    // to query on a given range, 3 conditions must be checked:
    // 1 - range represented by a node is completely inside the given range
    // 2 - range represented by a node is completely outside the given range
    // 3 - range represented by a node is partially inside and partially outside the given range
    /*
        If the range represented by a node is completely outside the
        given range, we will simply return 0. If the range represented
        by a node is completely inside the given range, we will return
        the value of the node which is the sum of all the elements in the
        range represented by the node. And if the range represented
        by a node is partially inside and partially outside the given range,
        we will return sum of the left child and the right child.
        Complexity of query will be O(logN).

    */

    int query(int no, int ini, int fim, int i, int j) {

        // first check if the range are not inside interval
        if(j < ini || i > fim) {
            // if it ends before the beginning of the interval
            // of start after the interval
            // range represented by a node is completely outside the given range
            return 0;
        }

        if (ini >= i && fim <= j) {
            // range represented by a node is completely inside the given range
            return st[no];
        }

        // range represented by a node is partially inside and partially outside the given range
        int mid = (ini + fim) >> 1;
        int ll = query(2*no, ini, mid, i, j);
        int rr = query(2*no+1, mid+1, fim, i, j);
        return (ll + rr);
    }
};

ostream& operator << (ostream& ostr, const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        ostr << v[i] << " ";
    }
    return ostr;
}
int main()
{
    vector<int>v = {1,3,5,7,9,11};
    SegmentTree stt(v);
    stt.constructST(1, 0, 5);
    cout << stt.a << endl;
    cout << "Sum from 0 to 5: " << stt.query(1,0,5,0,5) << endl;
    cout << "Update value in index 3 which is 7 to 0\n";
    stt.updatevalue(1,0,5,3,0); // to 0
    cout << stt.a << endl;
    cout << "Sum from 0 to 5: " << stt.query(1,0,5,0,5) << endl;
    cout << "Update value in index 5 which is 11 to 5\n";
    stt.updatevalue(1,0,5,5,5); // to 5
    cout << stt.a << endl;
    cout << "Sum from 0 to 5: " << stt.query(1,0,5,0,5) << endl;
    cout << "Sum from 0 to 1: " << stt.query(1,0,5,0,1) << endl;
    cout << "Sum from 0 to 2: " << stt.query(1,0,5,0,2) << endl;
    cout << "Sum from 0 to 3: " << stt.query(1,0,5,0,3) << endl;
    cout << "Sum from 3 to 4: " << stt.query(1,0,5,3,4) << endl;
    cout << "Sum from 2 to 5: " << stt.query(1,0,5,2,5) << endl;
    cout << "Sum from 2 to 4: " << stt.query(1,0,5,2,4) << endl;

    return 0;
}
