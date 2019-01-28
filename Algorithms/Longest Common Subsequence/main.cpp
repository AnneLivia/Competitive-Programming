#include <iostream>

using namespace std;

/*
    What is the longest common subsequence problem?
    The longest common subsequence (LCS) problem is the problem of
    finding the longest subsequence common to all sequences in a set of
    sequences.

    Applications: DNA Analise of two or more different organisms
                  A DNA is compound by a sequence of molecules, called bases:
                  Adenine, Chemin, guanine and cytosine.
    Given two DNA:
    S1 = ACCGTGGAAAAGGTTAAGGCCAGGATTTAACCGCGGGC
    S2 = ACCGCGGTTTAATCCGGATAGGTTGAAATGGTTGAAAC

    Is possible to answer, how much identical are those DNA, and so on.

    For abcd and acd, the answer is LCS(s1, s2) = acd

    Algorithm:
    Given two strings
    if s1m == s2n, must do: s1m - 1, s2n - 1 + s1m or s2m.
    otherwise: check what is the longest, s1m - 1 or s2m - 1.

    c(i,j) = { 0, if i = 0 or j = 0 }
             { c(i - 1, j - 1) + 1, if i == 1 }
             { max (c(i - 1, j), c(i, j - 1), if i != j}

    Table:
    x = BDCABA, Y = ABCBDAB
        yj  A  B  C  B  D  A  B
    xi   0  0  0  0  0  0  0  0
    B    0  0  1  1  1  1  1  1
    D    0  0  1  1  1  2  2  2
    C    0  0  1  2  2  2  2  2
    A    0  1  1  2  2  2  3  3
    B    0  1  2  2  3  3  3  4
    A    0  1  2  2  3  3  4  4
*/

// There are two cases, when the end of words matches and when it doesn't match,
// so it takes the maximum between the string 1 or string 2 by decreasing its size.
// Example: STR1: ABCD, STR2: AB.
// First call:

int result = 0;
// Recursive solution for LCS
int lcsRecursive(string s1, string s2, int indexS1, int indexS2) {
    if(indexS1 == 0 || indexS2 == 0) // base case
        return 0; // strings are empty, any char matches
    else {
        // If the end of the strings are equal, then return 1 + the sum of what is left
        if(s1[indexS1] == s2[indexS2]) {
            return 1 + lcsRecursive(s1, s2, indexS1 - 1, indexS2 - 1);
        } else {
            // if they are not equal, then, return maximum both from the string 1 or string 2
            return max(lcsRecursive(s1, s2, indexS1 - 1, indexS2), lcsRecursive(s1, s2, indexS1, indexS2 - 1));
        }
    }
}

string lcs(string s1, string s2) {
    int xSize = (int)s1.size(); // Getting size of string 1
    int ySize = (int)s2.size(); // Getting size of string 2


    int table[xSize + 1][ySize + 1]; // Creating table of size xSize + 1 and ySize + 1 so that the table is going to have either a free row and col to insert 0

    // Inserting 0 in the first row
    for(int i = 0; i < ySize + 1; i++) {
        table[0][i] = 0;
    }

    // Inserting 0 in the first col
    for(int i = 0; i < xSize + 1; i++) {
        table[i][0] = 0;
    }

    // Filling the table
    for(int i = 1; i <= xSize; i++) {
        for(int j = 1; j <= ySize; j++) {
            if(s1[i - 1] == s2[j - 1]) { // if S1[i] == s2[i], get table[i - 1, j - 1] (element of diagonal) and sum to 1
                table[i][j] = table[i - 1][j - 1] + 1;
            } else { // Otherwise, get the maximum, can be either table[i - 1][j] or table[i][j - 1]
                table[i][j] = table[i - 1][j] > table[i][j - 1] ? table[i - 1][j] : table[i][j - 1];
            }
        }
    }

    // Printing table

    for (int i = 0; i < xSize + 1; i++) {
        for(int j = 0; j < ySize + 1; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }

    // Finding what is the sequence

    return " ";
}

int main()
{
    cout << lcsRecursive("ABCB", "BDCAB", 4, 5) << endl;
    lcs("ABCB", "BDCAB");
    return 0;
}
