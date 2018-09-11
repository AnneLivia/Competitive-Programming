#include <iostream>
#include <cstring>

using namespace std;

/*
    Given a set of non-negative integers,
    and a value sum, determine if there
    is a subset of the given set with sum
    equal to given sum.
*/


bool subsetSum(int *vet, int tv, int s) {

    int lookupTable[tv][s + 1]; // Rows are number of numbers in the set, and s + 1 is the total number of possible sums
    memset(lookupTable, 0, sizeof(int) * ((tv)* (s + 1)));
    lookupTable[0][0] = 1; // First row and collum receives 1, because in the loop it wont be accessed
    for(int i = 1; i < tv; i++) {
        for(int j = 0; j < s + 1; j++) {
            if(j == 0)
                lookupTable[i][j] = 1; // All first column are 1, because, 0 number can reach the sum of 0
            else {
                if(lookupTable[i - 1][j] == 1)
                    lookupTable[i][j] = 1;
                else if (j - (vet[i]) >= 0) {
                    if(lookupTable[i - 1][j - (vet[i])]) {
                        lookupTable[i][j] = 1;
                    }
                }
            }
        }
    }

        for (int k = 0; k < (tv); k++) {
            for(int w = 0; w < (s + 1); w++) {
                cout << lookupTable[k][w] << " ";
            }
            cout << endl;
        }
}

int main()
{
    int vet[5] = {0,4,2,1,3};
    int sumToAchieve = 5;

    if(subsetSum(vet, 5, sumToAchieve))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
