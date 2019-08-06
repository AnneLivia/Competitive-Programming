#include <iostream>
#include <vector>

using namespace std;

/*
    Basic idea behind BIT (Fenwick tree)
        - There's an array from 0 to n + 1, where each position stores a sum of some positions
        - This positions that is used is specified by the LSB (least significant bit) of a index.
        - suppose we have an array of 8 position:
            index --- Binary --- LSB (Responsibility of the position)
            0      ---     0     ---   0       (0) -> it's going to store the sum of 0 position (just an extra index in the BIT array)
            1      --- 0001   ---   1       (1) -> it's going to store the sum of 1 position (just itself)
            2      --- 0010   ---   10     (2) -> it's going to store the sum of 2 positions (itself and the one before
            3      --- 0011   ---   1       (1) -> //
            4      --- 0100   ---   100   (4) -> it's going to store the sum of 4 position (itself and three positions before it)
            5      --- 0101   ---   1       (1) -> //
            6      --- 0110   ---   10     (2) -> //
            7      --- 0111   ---   1       (1) -> //
            8      --- 1000   ---   1000 (8) -> it's going to store the sum of 8 positions (itself and seven positions before it), basically the full array in this case
        With this, we still need to change the values and sum the values between some positions, but it's not all positions anymore, so the complexity in this case is O (log n)
        for both, update a value and get the sum between some specific range.
*/

vector<int>bit;
vector<int>v = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};


void update(int index, int value) {
    while(index < (int)bit.size()) {
        bit[index]+=value; // updating the sum
        // opposite to the sum, here we sum up with the LSB of the index
        index += index & (-index);
    }
}

// get the sum between some range in O(log n)
int get(int a) {
    // to get the sum, it's just needed to get the least significant bit of a value
    int sum = 0;
    while(a > 0) {
        sum+=bit[a]; // storing the sum store in position a of the tree
        a-=a&(-a); // removing the least significant bit
    }
    return sum;
}

// function to build the BIT
void build() {
    // creating array of v + 1 positions, so that we can count from 1 to v
    bit.assign((int)v.size() + 1, 0);
    for (int i = 1; i < (int)v.size() + 1; i++) {
        // for each index of the tree, pass value in the array, so that it will occur a update through all
        // the position of the tree
        update(i, v[i - 1]);
    }
}


int main()
{
    build();
    cout << "From 0 to 5: " << get(5) << endl;
    cout << "From 1 to 6: " << get(6) - get(1) << endl;
    return 0;
}
