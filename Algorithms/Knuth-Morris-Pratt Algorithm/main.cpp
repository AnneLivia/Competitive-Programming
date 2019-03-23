#include <vector>
#include <iostream>

using namespace std;

/*
    String Matching Problem:
        - String matching problem is the problem of finding all occurrences
        of a given pattern string in a text.
        - The context of the problem is to find out whether one string (called "pattern")
        is  contained  in  another  string.
        - String matching or searching algorithms try to find places where one or
        several strings (also called patterns) are found within a larger string (searched text)
        - This  problem  correspond  to  a  part  of  more  general one, called "pattern recognition".
    Some Applications:
        Text-editing software, web search engines, SPAM filters, natural language processing,
        computational biology (search a particular pattern in DNA sequence), feature detection
        in digital image, and many more.
    There are a lot of algorithm for pattern search, such as Knuth-Morris-Pratt.
    Basic idea behind KMP:
        When a mismatch is detected, our "false start" consists of characters that we know in
        advance (since they are in the pattern). somehow we should be able to take advantage of this
        information instead of backing up the i pointer over all those known characters.
        The idea behind KMP is to find how much to shift the word W when there is a mismatch.
        The basic idea behind KMPs algorithm is: whenever we detect a mismatch (after some matches),
        we already know some of the characters in the text of the next window.
        We take advantage of this information to avoid matching the characters
        that we know will anyway match.
    process to implement algorithm:
    In order to know how many character to shift we need to do some preprocessing step which is to calculate
    the LCP (longest common prefix which is also a suffix).
    Reference: http://www.mif.vu.lt/cs2/courses/ds99fa6.pdf

    Two steps:
        - prefix function
        - string matching
*/

// suffixes which is also a prefixes
void prefix_suffix(const string& s, vector<int>& ps) {
    int i = 1, j = 0;
    // while it's not the end of the word
    while(i < (int)s.size()) {
        // if chars matches
        if(s[i] == s[j]) {
            // save at position i of vector PS, the value j + 1, which means two things:
            // the position where we can start to avoid unnecessary comparisons and the size
            // of a specific prefix which is also a suffix
            ps[i] = j + 1;
            // increment both j and i to check another possible character that belongs to a prefix and suffix
            j++;
            i++;
        } else { // if it's not equal, we can have two cases:
            // if j is equal to 0, it means we haven't gone from the first position yet
            if(j == 0)
                i++; // increment i until it finds a suffix which matches with the first char of the string
            else // otherwise, if j is different of 0 and we get here, it means that we've found a mismatch, so
                j = ps[j - 1]; // get the position from the index saved at the last char position of j that already belongs to a suffix
        }
    }
}

int kmp(string s, const string& patt) {
    // vector to store information about prefix and suffix
    vector<int> ps((int)s.size(), 0);
    // avoid unnecessary comparisons
    // need to find biggest prefix which is a suffix
    prefix_suffix(s, ps);
    // printing PRE processing phase
    //for (int i = 0; i < s.size(); i++) {
    //    cout << ps[i] << " ";
    //}
    //cout << endl;

    cout << s << ", searching: " << patt << endl;
    // string matching step
    int i = 0, j = 0;
    // while it's not the end of the word minus the word we are searching (all chars from pattern fits in the string)
    while(i < (int)s.size()) {
        if(s[i] == patt[j]) {
            // increment both i and j
            i++; j++;
        } else {
            // otherwise, word was not found yet
            if(i < (int)s.size()) {
                // if the index of the original string hasn't reached the end of the string and
                // the chars doesn't match, we check if the index of the pattern string is different of 0, if it's not
                // we increment index of the original word by one
                if(j == 0)
                    i++;
                else {
                    j = ps[j - 1];
                }
            }
        }
        // if a pattern was already found
        if(j == (int)patt.size()) {
            // return i - size of pattern which marks the start position of the word
            // change letter to lower case and the found one to uppercase
            for (int k = 0; k < (int)s.size(); k++) {
                if(k >= (i - (int)patt.size()) && k < (i - (int)patt.size()) + (int)patt.size()) {
                    s[k] = toupper(s[k]);
                } else {
                    s[k] = tolower(s[k]);
                }
            }
            cout << "result: " << s << endl;
            return i - (int)patt.size();
        }
    }
    return -1; // was not found
}

int main()
{
    cout << "Found at: " << kmp("THISISATEXTTOCHECKIFTHEKMPALGORITHMWORKSFINE", "ALGORITHM") << endl;
    return 0;
}
