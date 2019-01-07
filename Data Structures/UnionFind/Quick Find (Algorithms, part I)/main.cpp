#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>

using namespace std;

/*
    In worst case, to change from one value to a different value an
    array of ids, after call the union function, it takes with the quick find
    data structure n - 1 time, since in the worst case, all of the entries except
    id[q] are changed from id[p] to id[q].

    Improvements can be done by using array of size to count which elements need less update
    Save in id their roots.
*/

/*
// Part 1
class QuickFind {
private:
    int *id, sizeArr;
public:
    QuickFind(int sizeArr) : sizeArr(sizeArr) {
        this->id = new int[sizeArr];
        // Initialize all elements as uniques components
        for (int i = 0; i < sizeArr; i++) {
            this->id[i] = i;
        }
    }

    // Checking if elements are already connected
    bool isConnected(int p, int q) {
        return (this->id[p] == this->id[q]);
    }

    // Union function to unify elements, make them part of the same component
    void unify(int p, int q) {
        int pid = this->id[p];
        int qid = this->id[q];

        // Change all with the same as id[p] to id[q]
        for (int i = 0; i < this->sizeArr; i++) {
            if(this->id[i] == pid)
                this->id[i] = qid;
        }
    }

    void showId() {
        for (int i = 0; i < this->sizeArr; i++) {
            if(i != 0)
                cout << " ";
            cout << this->id[i];
        }
        cout << endl;
    }

    ~QuickFind() {
        delete[] id;
        id = nullptr;
    }
};

// Part 2
class QuickUnion {
private:
    int *id, sizeArr;
public:
    QuickUnion(int sizeArr) : sizeArr(sizeArr) {
        this->id = new int[sizeArr];
        // Initialize all elements as uniques components
        for (int i = 0; i < sizeArr; i++) {
            this->id[i] = i;
        }
    }

    // Checking if p and q are connected
    bool connected(int p, int q) {
        return (detect(p) == detect(q)); // Depth of p and q
    }

    // Getting root of element
    int detect(int p) {
        while(p != this->id[p])
            p = this->id[p];
        return p;
    }

    // unify p and q
    void unify(int p, int q) {
        int rootp = detect(p);
        int rootq = detect(q);

        this->id[rootp] = rootq;
    }

    ~QuickUnion() {
        delete[] id;
        id = nullptr;
    }
};

// Part 3 (improvement 1) Weight
class QuickUnionWeighted {
private:
    int *id, *wt, sz;
public:
    QuickUnionWeighted(int sz) : sz(sz) {
        this->id = new int[sz];
        this->wt = new int[sz]; // Count number of objects in the tree rooted at i
        for (int i = 0; i < this->sz; i++) {
            id[i] = i;
            wt[i] = 1; // Initially it each one has 1 component
        }
    }

    bool connected(int p, int q) {
        return detect(p) == detect(q);
    }

    int detect(int p) {
        if(this->id[p] == p)
            return p;
        return detect(this->id[p]);

        //    while(p != this->id[p])
        //        p = this->id[p];

        //    return p;

    }

    void unify(int p, int q) {
        // Difference from quick union is that here:
        // Link root of smaller tree to root of larger tree
        // Update size of SZ[]
        int idp = detect(p);
        int idq = detect(q);

        if(idp == idq)
            return; // There's a cycle

        if(this->wt[idp] < this->wt[idq]) {
            // Smaller tree p is going to be linked to q
            this->id[idp] = idq;
            this->wt[idq]+=this->wt[idp]; // Now id Q has idq + idp elements
        } else {
            // Otherwise
            this->id[idq] = idp;
            this->wt[idp]+=this->wt[idq];
        }
    }

    ~QuickUnionWeighted() {
        delete[] wt;
        delete[] id;
        id = nullptr; wt = nullptr;
    }
};

// Part 3 (improvement 2) path compression
//  Just after computing the root of p,
//  set the id of each examined node to point to that root

class QuickUnionPathCompression {
    int *id, *wt, sz;
public:
    QuickUnionPathCompression(int sz) : sz(sz) {
        this->id = new int[sz];
        this->wt = new int[sz]; // Count number of objects in the tree rooted at i
        for (int i = 0; i < this->sz; i++) {
            id[i] = i;
            wt[i] = 1; // Initially it each one has 1 component
        }
    }

    bool connected(int p, int q) {
        return this->id[p] == this->id[q];
    }

    int detect(int p) {
        while(p != this->id[p]){
            this->id[p] = this->id[this->id[p]];
            p = this->id[p];
        }

        return p;
    }

    void unify(int p, int q) {
        // Difference from quick union is that here:
        // Link root of smaller tree to root of larger tree
        // Update size of SZ[]
        int idp = detect(p);
        int idq = detect(q);

        if(idp == idq)
            return; // There's a cycle

        if(this->wt[idp] < this->wt[idq]) {
            // Smaller tree p is going to be linked to q
            this->id[idp] = idq;
            this->wt[idq]+=this->wt[idp]; // Now id Q has idq + idp elements
        } else {
            // Otherwise
            this->id[idq] = idp;
            this->wt[idp]+=this->wt[idq];
        }
    }

    void showId() {
        for (int i = 0; i < this->sz; i++) {
            if(i != 0)
                cout << " ";
            cout << this->id[i];
        }
        cout << endl;
    }

    ~QuickUnionPathCompression() {
        delete[] wt;
        delete[] id;
        id = nullptr; wt = nullptr;
    }
};
*/

// union find
class UnionFind {
private:
    // Id stores its roots, SZ store its size, n is the number of elements and component is the number of components
    int *id, *sz, n, component;
public:
    UnionFind(int n) : n (n) {
        // Allocating memory for id and SZ of n size
        this->id = new int[this->n];
        this->sz = new int[this->n];
        // Number of components initially is the number of vertex
        this->component = n;
        // Each elements is its own root at the beginning
        for (int i = 0; i < this->n; i++) {
            this->id[i] = i;
            this->sz[i] = 1; // All are initially of size 1.
        }
    }

    // Find with path compression recursive
    int detect_ypathr(int p) {
        if(this->id[p] == p) // With p is equal to this->id[p], then return p.
            return p;
        return this->id[p] = detect_ypathr(this->id[p]); // When it returns back to this call, in the p position will be stored the root
    }

    // Find without path compression recursive
    int detect_npathr(int p) {
        if(p == this->id[p])
            return p;
        return detect_npathr(this->id[p]);
    }

    // Find iterative without path compression
    int detect_npathi(int p) {
        int root = p;
        while(root != this->id[root]) {
            root =  this->id[root];
        }

        return root;
    }

    // Find with path compression iterative
    int detect_ypathi(int p) {
        int root = p;
        // Find root
        while(root != this->id[root])
            root = this->id[root];
        // store in each connected component its respectively root
        while(p != root){
            int next = this->id[p];
            this->id[p] = root;
            p = next;
        }

        return root;
    }

    void unify(int p, int q) {
        if(connected(p,q))
            return; // Error, elements are already in the same component

        int rootp = detect_ypathr(p);
        int rootq = detect_ypathr(q);

        // Checking which component has more elements
        if(this->sz[rootp] < this->sz[rootq]) {
            // if the second one has more elements, then:
            // main root stores the number of elements it has in its component
            this->sz[rootq]+=this->sz[rootp];
            this->id[rootp] = rootq;
        } else {
            this->sz[rootp]+=this->sz[rootq];
            this->id[rootq] = rootp;
        }

        this->component--; // One less component
    }

    int getComponentSize() {
        return this->component;
    }

    int getElementSize(int p) {
        // getting the number of elements that is store in the root of element p
        return this->sz[detect_ypathr(p)];
    }

    int getSize() {
        return this->n;
    }

    bool connected(int p, int q) {
        return (detect_ypathr(p) == detect_ypathr(q));
    }

    ~UnionFind() {
        delete[] id;
        delete[] sz;
        id = nullptr; sz = nullptr;
    }
};


int main()
{

    UnionFind un(10);
    int p, q;
    while(cin >> p >> q) {
        if(un.connected(p,q)) {
            cout << "Elements are already connects\n";
        } else {
            un.unify(p, q);
            cout << p << " and " << q << " are now connected\n";
        }
        cout << "\n\n";
        cout << "Number of elements: " << un.getSize() << endl;
        cout << "Number of components: " << un.getComponentSize() << endl;
        for (int i = 0; i < un.getSize(); i++) {
            cout << "Number of elements from component: " << i << ": " << un.getElementSize(i) << endl;
        }
    }

    return 0;
}
