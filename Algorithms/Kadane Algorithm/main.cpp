#include <iostream>
#include <vector>

using namespace std;

/*
    Kadane is a algorithm to find the largest sum of a contiguous subArray.
    ------> -2 -3 4 -1 -2 -2 1 5 -3
    the maximum contiguous array sum here is: 4 + (-1) + (-2) + 1 + 5  = 7;

    Algorithm:
    real_max = 0;
    current_max = 0;

    loop for each element of the array
     current_max+=array[i];
     if(current_max < 0)
        current_max = 0;
     if(real_max < current_max)
        real_max = current_max;
    after that:
    return real_max;

*/

int kadane(const vector<int>&v) {
    int real_max = 0;
    int current_max = 0;

    for(int i = 0; i < (int)v.size(); i++) {
        current_max+=v[i];

        if(current_max > real_max)
            real_max = current_max; // Update the real_max with the new maximum sum

        if(current_max < 0) // Negative numbers are not allowed
            current_max = 0;

        // if is neither negative nor more than real_max the variable will keep the sum
    }

    return real_max;
}

int main()
{
    vector<int>v;
    int n = 0;
    while(n != 100) {
        cout << "Type an number, 100 to quit: ";
        cin >> n;
        v.push_back(n);
    }

    v.pop_back(); // Deleting the number 100
    int k = kadane(v);

    cout << "Maximum sum: " << k << endl;
    return 0;
}
