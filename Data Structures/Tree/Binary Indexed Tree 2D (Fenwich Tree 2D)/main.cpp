#include <iostream>
#include <vector>

using namespace std;
/*
    Binary Indexed Tree 2D solves problems about queries in a sub area
    of an array.
    2D Fenwick tree also requires the operation to be invertible. i.e
    Before using BIT, must confirm that the problem is associative, that is:
    >> f(f(a, b), c) = f(a, f(b, c))
        >> addition has inverse subtraction that's why we do x-=(x&-x) and x+=(x&-x)
        >> Multiplication has inverse division
        >> GCD() has no inverse, so we can't use BIT to calculate range GCD
        >> sum of matrices has inverse

    Remember basic operations:
    x & (-x) -> gives last set bit and that bit is going to specify index
    which is responsible for.
    query(i,j) in a 1D Fenwick Tree is query(0, j) - query(0, i - 1);
    Example: query (0, j)     = [ . . . . . . . . . . ]
             query (0, i - 1) = [ . . . ]            -
             __________________________________________
             query(i, j)      =       [ . . . . . . . ]
    for a 2D version, the operation is based on the inclusion exclusion principle
    the operation is similar to what we do in a integral image where we have four
    vertexes representing an entire subrange.

    ...............
    .             .
    .             .
    .   v1 ........ v3
    .      .      .
    .      .      .
    .   v2 .      .
    ............... v4

    to get the sum of one specific sub area, such as the one represented by the above example
    we could perform v4 - (v2 + V3) + V1. since v1 is removed twice when subtracting v4 and v2 and v4 and v3
    since both v2 and v3 also keeps the sum of v1, we ended up removing v1 twice, that's why we need to add it again

    although a query from a integral image can be done in O(1), to update a value in it, the complexity would be
    in a simplified way, O(n*m).
    but with 2D Fenwick tree those operations can be done in O(log nm).

    the operation in a 2D BIT is:
        supposing
        sum((0,0), (x2, y2)) -> gets the sum of the full array, this could be seen as v4 in the example above.
        then we subtract it by sum((0,0), (x1 - 1, y2))
        then subtract by sum((0,0), (x2, y1 - 1))
        then add up sum((0,0), (x1 - 1, y1 - 1)) since it was removed twice
    2D Fenwick tree is implemented as a matrix of the same size as target matrix.

*/

class FenwickTree2D {
private:
    vector<vector<int> > fk2d;
    int rows, cols;

    int lsb(int n) {
        return n & (-n);
    }

    void build(const vector<vector<int> > & matrix) {
        for(int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                update(i+1, j+1, matrix[i][j], 0);
            }
        }
    }

public:
    FenwickTree2D(int row, int col, const vector<vector<int> > matrix) : rows(row), cols(col) {
        // 0 is dumb index
        fk2d.assign(rows+1, vector<int>(cols+1, 0));
        build(matrix);
    }

    void print() {
        for (int i = 1; i < rows+1; i++) {
            for (int j = 1; j < cols+1; j++) {
                cout << fk2d[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void update(int x, int y, int value, int aux) {

        for (int i = x; i < rows+1; i+=lsb(i)) {
            for (int j = y; j < cols+1; j+=lsb(j)) {
                this->fk2d[i][j]-=aux;
                this->fk2d[i][j]+=value;
            }
        }
    }

    int query(int x, int y) {
        int sum = 0;
        // do individual queries
        for (int i = x; i > 0; i-=lsb(i)) {
            for (int j = y; j > 0; j-=lsb(j)) {
                sum+=fk2d[i][j];
            }
        }
        return sum;
    }

    int query(int x1, int y1, int x2, int y2) {
        // D - (B+C) + A -> similar to integral image query operation (inclusion and exclusion principles)
        return (query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1,y1 - 1));
    }
};

int main()
{
    int rows = 4, cols = 4;
   // cout << "Rows number: ";
   // cin >> rows;
   // cout << "Cols number: ";
   // cin >> cols;

    //cout << "Insert values in array: ";
    vector<vector<int> > matrix =
                    {{1, 2, 3, 4},
                    {5, 3, 8, 1},
                    {4, 6, 7, 5},
                    {2, 4, 8, 9}};

    FenwickTree2D fk(rows, cols, matrix);
    fk.print();
    // 1 to n notation
    cout << "Query(2,2,3,4) = " << fk.query(2,2,3,4) << endl;
    fk.update(3, 3, 2, matrix[2][2]);
    matrix[2][2] = 2;
    cout << "Query(2,2,3,4) after update = " << fk.query(2,2,3,4) << endl;
    return 0;
}
