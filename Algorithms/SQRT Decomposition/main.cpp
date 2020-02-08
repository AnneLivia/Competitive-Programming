#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

/*
    Sqrt Decomposition is a method (or a data structure)
    that allows you to perform some common operations
    (finding sum of the elements of the sub-array,
    finding the minimal/maximal element, etc.)
    in O(sqrt(n)) operations.

    The idea is to divide a specific array of size n in sqrt(n)
    parts. in each one of those blocks, contains specific informations

    After the preprocessing of the array, we can perform operations like
    query a..b and also update a specific point
    where update take O(1) and query takes O(sqrt(n) + sqrt(n) + sqrt(n))
    which is O (3 * sqrt(n)) -> O (sqrt(n)).
    Since in the queries the jumps are done sqrt(n) times.


    Example: A = [1,2,3,4,5]
    size = sqrt(5) = 2, need to dive A into 3 chunks
    where:
    A1[1,2], A2[3,4], A3[5]. the last chunk has only one value because 5 is not a perfect square

    - update just need to access the position in array
    - query, just need to
*/

class sqrtDecomp {
private:

    vector<int>blocks;
    int tam, sqrtParts;

    void build() {
        // this method is going to be used to separate the array
        // into sqrt(tam) blocks

        int block = -1;

        for (int i = 0; i < tam; i++) {

            if (i % sqrtParts == 0) {
                // when i % sqrtParts is equals to 0
                // we've found a limit between each chunk
                // suppose we have an array of size 5, the sqrt(5) is 2 (integer)
                // 0 % 2 == 0 ? yes, block++, goes to 0 since it starts at -1,
                // 1 % 2 == 0 ? no,
                // 2 % 2 == 0 ? yes, block++; goes to 1, next block after 0
                // 3 % 2 == 0 ? no,
                // 4 % 2 == 0 ? yes, block++, goes to block 3
                // 5, stops the loop, and in the block 3, the value in the last position was saved
                // so this condition here is to mark the begin/end of a block
                block++;
            }

            // each chunk is going to save the sum
            blocks[block]+=data[i];
        }
    }

public:
    vector<int>data;
    sqrtDecomp(const vector<int>& v) {
        data = v;
        tam = (int)v.size();
        sqrtParts = (int)sqrt(tam);
        blocks.assign(sqrtParts + 1, 0); // plus 1 to allow not perfect squares
        build();
    }

    // query is O(sqrt(n))
    int query(int i, int j) {
        int sum = 0;
        // the idea is get the sum in first part of the array, then, get
        // the sum in between the first and last block
        // get sum in the first block if necessary
        while(i < j && i % sqrtParts != 0) {
            // while l is less than R and
            // is not in the limit of the block and also is
            // different of 0, that is
            sum+=data[i];
            i++;
        }

        // then get sum of the blocks in between l and r if exists
        while(i + sqrtParts <= j) {
            sum+=blocks[i/sqrtParts];
            i+=sqrtParts; // it gives sqrt jumps
        }

        // then get the last part sum if there exists
        while(i <= j) {
            sum+=data[i];
            i++;
        }

        return sum;
    }

    // update is O(1)
    void update(int i, int va) {
        // suppose I want to update value in position 3 in a array of size 5
        // 3 / 2 = 1, chuck 1
        // update(4) = 4 / 2 = 2, chunk 2,
        // update(1) = 1 / 2 = 0, chuck 0,
        // update(2) = 2 / 2 = 1, chuck 1,
        // so, by dividing the value by the sqrt(n), we get the specific chunk of the index
        // to update, need to get the value - the previous one, then add up the new one
        blocks[i/sqrtParts]+=va - data[i];
        // the update in the array
        data[i] = va;
    }
};

ostream& operator << (ostream& ostr, const vector<int>&v) {
    for (int i = 0; i < (int)v.size(); i++) {
        if (i != 0)
            ostr << ",";
        ostr << v[i];
    }
    return ostr;
}

int main()
{
    vector<int> v = {1, 5, 2, 4, 6, 1, 6, 6, 2};
    sqrtDecomp s(v);
    int op, x, y;
    while(true) {
        cout << s.data << endl;
        cout << "1 - Update\n2 - Query\n3 - Quit\n" <<
        "Type Here in order op, x, v/y: ";
        cin >> op;

        if (op == 3)
            break;
        cin >> x >> y;
        if (op == 1) {
            s.update(x, y);
        } else if (op == 2) {
            cout << "Query ("<< x << "," << y << ") = " << s.query(x, y) << endl;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
