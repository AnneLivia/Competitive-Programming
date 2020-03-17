#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long unsigned int n, x, y, diag, p, grea;
    cin >> n;
    while(n--) {
        cin >> x >> y;

        // getting diag of the greatest one
        grea = x > y ? x : y;
        
        /*  
            The Diagonal pattern is incresing from 2 to 2, that is: 2 4 6 8 10 12...
            The diagonal is the current increase interval obtained by (2 * (grea - 1));
            added up by the previous interval numbers. Example:
            The value in the diagonal 5x5 is 21.
            2 * (grea(5) - 1) = 8 -> 8 is the current interval increase
            to get the right value, add up the previous ones, that is 6, 4, 2 and 1
            to add up it in constant time must use PA formula that gives the sum of N numbers
            that shares the same constant factor. Since I need the sum from 8 to 2, where factor is 2
            the formula to use is:
            PA = ((initial + final) * Number of terms) / 2;
               = ((2 + p(8)) * (grea(5) - 1)) = 20 + 1, to get only odd numbers, becomes 21

            Example of spiral array
            1  2  9  10
            4  3  8  11
            5  6  7  12
            16 15 14 13
            
            
        */

        p = 2 * (grea - 1); // increase difference 

        // pa formula
        diag = (((2 + p) * (grea - 1)) / 2) + 1;

        // if greatest number is odd increase UP(x), decrease LEFT (y)
        // otherwise, decrease (UP), increase LEFT (Y)

        bool even = !(grea & 1) ? true : false;

        if (x != y) {
           // y - x gives the number of times the number must increase from diagonal to the row or col
           if (even)
                cout << diag - (y - x) << endl;
           else
               cout << diag + (y - x) << endl;
        } else {
            // if x is equal to y, the value is the diag value
            cout << diag << endl;
        }
    }
    return 0;
}