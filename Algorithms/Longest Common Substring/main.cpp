#include <iostream>
#include <vector>

using namespace std;
/*
    In the common longest substring, apart from, Longest common Subsequence
    substring are required to occupy consecutive positions within the original sequences.

    The LC substring for: "ABABC" and "BABCA" is BABC. Other common substring are ABC, A, AB, B, BA, BC and C.

    The solution using DP is:
    if string1[i] == string2[j], then: table[i][j] = 1 + table[i - 1][j - 1]; // Which means the length of substring before adding this new char
    otherwise, table[i][j] = 0;
    The length is equal to the maximal of these longest common suffixes of all possible prefixes
*/

string lcs(string& s1, string& s2, int n, int m) {
    vector<vector<int> >table(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    // Since its a substring, then it guarantee that all char
    // are in contiguous, then, I can just take the end of it,
    // and the begin of it can be the end minus the size
    int maximum = 0, endInxed = 0;
    for (int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(s1[i - 1] == s2[j - 1])
                table[i][j] = 1 + table[i - 1][j - 1];
            if(table[i][j] > maximum) {
                maximum = table[i][j];
                endInxed = i; // for string s1.
            }
        }
    }
    return s1.substr(endInxed - maximum, endInxed);
}

int main()
{
    string s1 = "ABC";
    string s2 = "BABA";
    cout << lcs(s1, s2, s1.size(), s2.size()) << endl;
    return 0;
}
