#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/*
    Longest palindromic subsequence (LPS):
    That can be solve using DP.
    One string is given, and from that string we have to find the longest length subsequence
    Example: BBBAB
    Maximum length is 4, BBBB
    Example: CBBD
    maximum length is 2, BB
*/

/*
 Naive solution O(2^n)
    C B B D
    Every single character is a palindrome of length 1, so:
    L(i, i) = 1.

        C B B D
    C   1
    B     1
    B       1
    D         1

    // If first and last characters are not same
    If (X[i] != X[j])
        L(i, j) =  max{L(i + 1, j), L(i, j - 1)}
    if words don't match, like C and D, considered, either C and B and B and D,
    i + 1, j or i, j - 1;

    // If there are only 2 characters and both are same
    Else if (j == i + 1) // there are only two characters and both are the same
        L(i, j) = 2 return 2 then

    // If there are more than two characters, and first and last
    // characters are same
    Else L(i, j) =
        L(i + 1, j - 1) + 2, 2 characters here.
*/
int lps(string s, int i, int j) {
    // if i is equal to j, it means that we are checking one single character
    if(i == j) {
        // every character is a palindrome itself
        return 1;
    }
    // if the characters are equal, and i + 1 is equal to j, it means that we have only 2 character, so return 2
    if(s[i] == s[j] && i + 1 == j) {
        return 2;
    }

    // there are more than 2 character if it get here
    // check if they are equal, if it is, return 2 + the calculation of what is left
    if(s[i] == s[j]) {
        // both i + 1 and j - 1 was already calculated
        return 2 + lps(s, i + 1, j - 1);
    } else {
        // chars are not the same
        return max(lps(s, i + 1, j), lps(s, i, j - 1));
    }

    /*
        Simulation:
            A B B D, i = 0, j = 3. is A == D? no, then
                -- A B B, i = 0, j = 2, is A == B? no, then
                    -- A B, i = 0, j = 1, is A == B? no, then
                        -- A, i = 0, j = 0,
                            is i == j? then return 1, A == A, single character
                    1 ----------------------------------------------------------
                        -- B, i = 1, j = 1,
                    1 ----------------------------------------------------------
                            is i == j? then return 1, B == B, single character
                    -- B B, i = 1, j = 2, is B == B? yes, then
                        i + 1 == j, yes, there are only two chars, then return 2
                2 --------------------------------------------------------------
                -- B B D, i = 1, j = 3, is B == D? no, then
                    -- B B, i = 1, j = 2, is B == B? yes
                            return 2
                    2 ----------------------------------------------------------
                    -- B D, i = 2, j = 3, is B == D? no, then
                        -- B, i = 2, j = 2, return 1 (single char)
                    1 ----------------------------------------------------------
                        -- D, i = 3, j = 3, return 1, (single char)
                    1 ----------------------------------------------------------
                    ..
                2 --------------------------------------------------------------
            ..
        ..
    ..
    max is 2.
    */
}

int dpLPS(string s) {
    vector<vector<int> > lp((int)s.size(), vector<int>((int)s.size(), 0));
    // all single is a palindrome of size 1
    for (int i = 0; i < (int)s.size(); i++) {
        lp[i][i] = 1;
    }

    // size of palindrome can be either 2 or more (size of string), so starting from string of size 2
    for (int si = 2; si <= (int)s.size(); si++) {
        // goes from 0 to the specific size
        for(int i = 0; i < (int)s.size() - si + 1; i++) {
            // j is the last character
            int j = i + si - 1; // getting the last char
            if(s[i] == s[j]) {
                // if are the same and length is 2, insert 2 as longest subsequence
                if(si == 2)
                    lp[i][j] = 2;
                else {
                    // otherwise, get the number at the position i + 1 and j - 1 + 2
                    lp[i][j] = lp[i + 1][j - 1] + 2;
                }
            } else {
                // if it's not equal, then insert the maximum from without the first or the last
                lp[i][j] = max(lp[i+1][j], lp[i][j - 1]);
            }
        }
    }
    return lp[0][(int)s.size() - 1];
}

int main()
{
    cout << dpLPS("BBBAB") << endl;
    return 0;
}
