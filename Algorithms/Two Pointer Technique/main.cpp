#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    Two pointer is really an easy and effective technique which is typically
    used for searching pairs in a sorted arrays.
    For example: Given a sorted array A (sorted in ascending order), having N integers, find if there exists any pair of elements
    (A[i], A[j]) such that their sum is equal to X.

    Example:
    1 7 8 9 10 11, X = 17
    We have two pointer, i and j,
        - i points to the first element of the array
        - j points to the second element
    While I move the i pointer, the sum increases, and while I move the j pointer, the sum decreases
    1 7 8 9 10 11
    i                  j     = v[i] (1)+ v[j] (11)== X(17)? no, then is smaller?  yes(12 < 17), then move i one step to the right
       i               j     = v[i] (7)+ v[j] (11)== X(17)? no, then is smaller?  no, then is greater? yes(18 > 17), then move j one step to the left
       i              j      = v[i] (7)+ v[j] (10) == X(17)? yes
*/

bool sumPair(int x, vector<int>& v) {
    sort(v.begin(),v.end());

    int pi = 0, pj = (int)v.size() - 1;

    while(pi < pj) {
        if(v[pi] + v[pj] == x) {
            return true;
        } else {
            if(v[pi]+v[pj] < x) {
                // value is smaller, needs to be increased
                pi++;
            } else {
                // value is not smaller, need to be decreased
                pj--;
            }
        }
    }
    // if it gets here, it wasn't found a sum that adds up to x
    return false;
}

int main()
{
    vector<int>v = {1,2,3,45,6,2,12};
    cout.setf(ios::boolalpha);
    cout << sumPair(16, v) << endl;
    return 0;
}
