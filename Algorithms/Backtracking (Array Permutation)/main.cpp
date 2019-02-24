#include <iostream>
#include <vector>

using namespace std;

/*
    Permutation of an array using the backtracking technique which
    finds all possible solutions without repeating.
*/

ostream& operator << (ostream& stream, const vector<int>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        stream << v[i] << " ";
    }
    return stream;
}

void permutation(vector<int>& v, int index, int arraySize, string space = "") {
    cout << space << "permutation(v, " << index << ", " << arraySize << ")" << endl;
    /*
        permutation([1,2,3], 0, 3, "")
            i == 0
                swap(array[0], array[0]);
                permutation([1,2,3], 1, 3, "") -> index + 1
                i = 1
                    swap(array[1], array[1]);
                    permutation([1,2,3], 2, 3, "") -> index + 1
                    base case ->> print([1,2,3])
                    swap(array[1], array[1]); -> ->> [1,2,3] again (backtracking)
                i = 2
                    swap(array[1], array[2]);
                    permutation([1,3,2], 2, 3, "") -> index + 1
                    base case ->> print([1,3,2])
                    swap(array[1], array[2]); ->> [1,2,3] again (backtracking)
                i = 3
                    break loop;
            i == 1
                swap(array[0], array[1]);
                permutation([2,1,3], 1, 3, "") -> index + 1
                i = 1
                    swap(array[1], array[1]);
                    permutation([2,1,3], 2, 3, "") -> index + 1
                    base case ->> print([2,1,3])
                    swap(array[1], array[1]); ->> [2,1,3] again (backtracking)
                i = 2
                    swap(array[1], array[2]);
                    permutation([2,3,1], 2, 3, "") -> index + 1
                    base case ->> print([2,3,1])
                    swap(array[1], array[2]); ->> [2,1,3] again (backtracking)
                i = 3
                    break loop;
            i == 2
                swap(array[0], array[2]);
                permutation([3,1,2], 1, 3, "") -> index + 1
                i = 1
                    swap(array[1], array[1]);
                    permutation([3,1,2], 2, 3, "") -> index + 1
                    base case ->> print([3,1,2])
                    swap(array[1], array[1]); ->> [3,1,2] again (backtracking)
                i = 2
                    swap(array[1], array[2]);
                    permutation([3,2,1], 2, 3, "") -> index + 1
                    base case ->> print([3,2,1])
                    swap(array[1], array[2]); ->> [3,1,2] again (backtracking)
                i = 3
                    break loop;
            i == 3
                break loop;
        finish function
    */
    // Base case
    if(index == arraySize - 1) {
        cout << "->>>> " << v << endl;
    } else {
        for (int i = index; i < arraySize; i++) {
            swap(v[index], v[i]);
            permutation(v, index + 1, arraySize, space + " ");
            swap(v[index], v[i]); // Backtrack phase (reordering array)
        }
    }
}

int main()
{
    vector<int> v = {1,2,3};
    permutation(v, 0, 3);
    return 0;
}
