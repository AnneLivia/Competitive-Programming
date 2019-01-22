#include <iostream>
#include <vector>

using namespace std;

/*  Shell sort algorithm, also known as n-gap insertion sort, shell's method, was
    proposed by Donald Shell in 1959.
    ShellSort is mainly a variation of the insertion sort. In insertion sort
    the elements are moved only one position ahead, since, when an element is far
    away, there's many movements to swap the positions, shellSort, in order to
    make it faster, allows to exchange elements in a given gap (interval), this
    gap is specified by a number H, which can be calculated using the Knuth's formula.
    this value is reduced until it becomes 1, when it becomes one, the insertion sort
    technique is done with all elements, in order to make it completely sorted.

    Knuth's formula: h = h * 3 + 1, where h is the interval with initial value 1
    The set of items in a h distance are sorted, in this way:
        the element in the position x is compared with (and swapped if necessary)
        with the element in the position x - h.
        The resultant vector is compound of h items sorted and intertwined, this vector
        is said to be h-sorted.
        when h == 1, the sort is similar to insertion sort algorithm.
    Example:
    [35, 33, 42, 10, 14, 19, 27, 44], to calculate the gap using Knuth's formula we need to use a loop while
    the number is less than the length of the array divided by three or only the length of the array, but then
    divided it by three at the start of the loop. ( // 3x+1 increment sequence:  1, 4, 13, 40, 121, 364, 1093, ...)
    sizeArray = 5, (8/3 = 2).
    h = 1, h (1) = h(1) * 3 + 1 = 4.
    4 < 2 ? no. then, stop loop, and h == 4
    so the interval starts with 4.The comparisons are going to be:
    {35,14}, {33,19}, {42, 27}, {10,44}.
    Each of these values are compared and if there's need to swap them, they are swapped in the original array.
    {14,35}, {19,33}, {27, 42}, {10, 44}. After this, the array looks like this:
    [14, 19, 27, 10, 35, 33, 42, 44]. Now the H value is updated, that is done with this formula: (h - 1)/3
    so, h(4) - 1 / 3 = 3 / 3 = 1, now h == 1, that's the new interval (gap).
    [14, 19, 27, 10, 35, 33, 42, 44], this generates two sublists {14, 27, 35, 42}, {19, 10, 33, 44}
    and then the original insertion sort is done, the result is:
    [10, 14, 19, 27, 33, 35, 42, 44].
    Another example taken from be a better programmer website:
    for a array of number: [3,5,4,7,2,1], gap starts with 4
    Iteration #1, gap 4 : [3 5 4 7 2 1] [(3) 5 4 7 (2) 1] = [(2) 5 4 7 (3) 1]

    Iteration #2, gap 4 : [2 5 4 7 3 1] [2 (5) 4 7 3 (1)] = [2 (1) 4 7 3 (5)]

    // Now traditional insertion sort algorithm is done:

    Iteration #3, gap 1 : [2 1 4 7 3 5] [(2) (1) 4 7 3 5] = [(1) (2) 4 7 3 5]

    Iteration #4, gap 1 : [1 2 4 7 3 5] [1 (2) (4) 7 3 5] = [1 (2) (4) 7 3 5]

    Iteration #5, gap 1 : [1 2 4 7 3 5] [1 2 (4) (7) 3 5] = [1 2 (4) (7) 3 5]

    Iteration #6, gap 1 : [1 2 4 7 3 5] [1 2 4 (7) (3) 5] = [1 2 4 (3) (7) 5] [1 2 (4) (3) 7 5] = [1 2 (3) (4) 7 5] [1 (2) (3) 4 7 5] = [1 (2) (3) 4 7 5]

    Iteration #7, gap 1 : [1 2 3 4 7 5] [1 2 3 4 (7) (5)] = [1 2 3 4 (5) (7)] [1 2 3 (4) (5) 7] = [1 2 3 (4) (5) 7]
    Finishes algorithm, final result is: [1 2 3 4 5 7]
*/

void shellsort1(vector<int>&v) {
    int h = 1; // h starts with gap 1
    // 3h+1 increment sequence:  1, 4, 13, 40, 121, 364, 1093, ...It could be one, but since h starts with 1 here, the minimum gap possible is 4
    while(h < (int)v.size() / 3) // That's Knuth's formula to choose a gap
        h = 3 * h + 1;
    // Now starting loop from gap to 1, where the pass is h = (h - 1) / 3;
    for(int i = h; i > 0; i = (h = (--h/3))) { // loop responsible to decrease h
        for (int j = h; j < (int)v.size(); j+=h) { // loop responsible to specify number in the specific gap position
            for(int k = j; k > 0 && v[k] < v[k - h]; k-=h) {
                swap(v[k],v[k - h]);
            }
        }

        // h = ((h - 1) / 3)
    }
}

// Algorithm from geeks for geeks
void shellSort2(vector<int>&v) {
    // Starting with a big gap, and the gap is reduced by dividing it by 2
    for (int gap = (int)v.size()/2; gap > 0; gap/=2) {

        // Gap insertion sort for this "gap" interval:
        for(int i = gap; i < (int)v.size(); i+=1) {
            int temp = v[i]; // getting value that is going to be compared with other elements gap positions before it
            int j;
            for (j = i; j >= gap && temp < v[j - gap]; j-=gap) {
                v[j] = v[j - gap]; // swapping all to gap position ahead
            }

            v[j] = temp; // putting temp in its correct location
        }
    }
}

int main()
{
    vector<int>v1 = {3,5,4};
    vector<int>v2 = {3,5,4,44,26,2};
    cout << "Before ShellSort1: ";
    for(auto i : v1)
        cout << i << " ";
    cout << endl;
    shellsort1(v1);
    cout << "After ShellSort1: ";
    for(auto i : v1)
        cout << i << " ";
    cout << endl;
    return 0;
}
