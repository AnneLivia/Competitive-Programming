#include <iostream>
#include <vector>

using namespace std;

/*
    Given a string s, find length of the longest prefix which is also suffix.
    The prefix and suffix should not overlap.
    Example:
        AABCDAABC
    Output: 4
    AABC is the longest prefix and suffix for the string above.
        ABCAB
    Output: 2
    AB is the longest prefix and suffix for the string above.
        AAAA
    Output: 2
    AA is the longest prefix and suffix for the string above. (not, don't overlap)
    Simple solution: Since overlapping of prefix and suffix is not allowed, we
    break the string from middle and start matching left and right string. if they are
    equal return size of any one string else try for shorter lengths on both sides.
*/

int lps_simple_solution(string word) {
    // Getting the size of the string
    int wordLength = (int)word.size();
    // if the word is less or equal to one, it means that we do not have a
    // prefix that is also a suffix, the word either is empty or has only one
    // character and it's not allowed overlap.
    if(wordLength <= 1)
        return 0;
    // If it get here, we can divide the string in the middle
    int middle = wordLength >> 1;
    // variable to start at the begin of the string, since we must loop the prefix
    int prefix = 0;
    // while the middle is less than the wordLength
    // so that we can check the prefix with the suffix
    cout << "Word: " << word << endl;
    while(middle < wordLength) {
        cout << "Prefix index: " << prefix << "\nMiddle index: " << middle << endl;
        cout << "Char at " << prefix << ": " << word[prefix] << endl;
        cout << "Char at " << middle << ": " << word[middle] << endl;
        // if the char at the middle position is equal to char at the prefix position
        // we can move one step ahead for both.
        if(word[middle] == word[prefix]) {
        // we already have partial word from size of at least 1 that is prefix which is also a suffix
            middle++;
            prefix++;
        } else {
            // if the chars above doesn't match, it means that they are not prefix and suffix
            // so we now must check two conditions, one which happens when the first character
            // doesn't move, and the other when it does moved, but now the character that it has
            // reached doesn't match with the current one indicated at index "middle".
            if(prefix == 0) {
                // if it gets in this condition, it means that the first character of the string doesn't match with
                // the middle one, so we need to move the middle index one step ahead.
                // so that we can check for another characters with the first one.
                middle++;
            } else {
                // in case it gets here, it means that some character indicated with the middle index
                // have matched with the ones indicated with the prefix index, so it means that there
                // must have a prefix which is also a suffix there, but it is not as large as it should be
                // if both chars were equal. So, what it must happen is that we must decrease the length by one.
                --prefix;
            }
        }
        // now return the prefix index which indicate the size that is also the last index it was
    }
    return prefix;
}

// Efficient solution is to use the preprocessing algorithm of KMP (Knuth-Morris-Pratt) search
// that we use the preprocessing algorithm where we build a LPS array which store following values
// Time Complexity : O(n)
// Auxiliary Space : O(n)
/*
    How it's compute if prefix is the same suffix
    Pattern: a b c d a b c a
    Steps:
        using 2 iterators, we check if two characters are equal by compare each other.
        if it's equal we increment both iterator, otherwise, we increment only one, so that the
        same character that was used before can be compared with another one.
    A prefix table is going to have a number that belongs to a corresponding prefix and for each
    prefix it represents the length of the longest suffix of this string that matches prefix.
    Example for the word "ababaca":
    i   s[0:i]        p[i]      matching prefix/suffix
    0     a            0                -
    1     ab           0                -
    2     aba          1                a
    3     abab         2                ab
    4     ababa        3                aba
    5     ababac       0                -
    6     ababaca      1                a
    Step by Step:
    Pattern: a b c d a b c a
    The first character has a maximum length undefined, but we refer to it as 0, a cannot have be both suffix and prefix
    OBS: this may have overlap.
    i = 0; j = 1; // i starts at the first position and j starts at the second position
    i j
    a b c d a b c a
    0 - - - - - - -
    string[i] == string[j]? no, so move the j to the next position and i stays at the same
    i   j
    a b c d a b c a
    0 0 - - - - - -
    string[i] == string[j]? no, so move the j to the next position
    i     j
    a b c d a b c a
    0 0 0 - - - - -
    string[i] == string[j]? no, so move the j to the next position
    i       j
    a b c d a b c a
    0 0 0 0 - - - -
    string[i] == string[j]? yes, so we pick whatever is the number of i which specifies both
    position and the length of the prefix and we add up by 1. So i is 0, we must do 0 + 1 = 1,
    and we move both, i and j one position ahead
      i       j
    a b c d a b c a
    0 0 0 0 1 - - -
    string[i] == string[j]? yes, so we pick whatever is the number of i which specifies both
    position and the length of the prefix and we add up by 1. So i is 1, we must do 1 + 1 = 2,
    and we move both, i and j one position ahead.
        i       j
    a b c d a b c a
    0 0 0 0 1 2 - -
    string[i] == string[j]? yes, so we pick whatever is the number of i which specifies both
    position and the length of the prefix and we add up by 1. So i is 1, we must do 2 + 1 = 3,
    and we move both, i and j one position ahead.
          i       j
    a b c d a b c a
    0 0 0 0 1 2 3 -
    string[i] == string[j]? no, now, since there's a mismatch, what is do is basically check the
    value store at the prefix table of the previous one, which is this case is the one that represents
    the character c and we assign that position to the i iterator, so that we return to that specific position
    so prefixTable[i - 1] is 0, so now i = 0.
    i             j
    a b c d a b c a
    0 0 0 0 1 2 3 -
    now we compare again
    string[i] == string[j]? yes, so we pick whatever is the number of i which specifies both
    position and the length of the prefix and we add up by 1. So i is 0, we must do 0 + 1 = 1,
    and we move both, i and j one position ahead. since it's the end of the word, we stop and we
    get the complete prefix table with all the longest prefix which is also a suffix values.
    a b c d a b c a
    0 0 0 0 1 2 3 1

*/

void printWord(const string& s, int i) {
    string copyS = s.substr(0, i);
    cout << copyS << endl;
}

int lps_kmp(string word) {
    //create an auxiliary array that will store the length of the prefixes which is also suffixes
    vector<int>lps((int)word.size(), 0);
    // the first position is 0
    int i = 0, j = 1; // iterator to move over the string
    // while j hasn't get to the end of the string we keep running our algorithm
    while(j < (int)word.size()) {
        // If the character at the position i and j are equal, insert there the number
        // of i which can represent the length of the prefix and the amount of characters
        // checked so far that matched with other characters.
        if(word[i] == word[j]) {
            lps[j] = i + 1;
            // i and j move one position, since the current position already match
            i++;
            j++;
        } else {
            // if they are not equal, then we must check what is the value of the previous
            // position of i, that's where we are going to move the i iterator and j stays at the
            // same position in case the i index is different of 0 it means that we already have some
            // prefix character here
            if(i != 0)
                i = lps[i - 1];
            else {
                lps[j] = 0; // just insert 0 here and increment j by one
                j++;
            }
        }
    }
    cout << "Index - LPS - prefix/suffix\n";
    for (int i = 0; i < (int)word.size(); i++) {
        cout << " " << i <<  " ---- " << lps[i] << " ------ ";
        printWord(word, i+1);
        cout << endl;
    }
    return lps[(int)word.size() - 1];
}

int main()
{
    cout << lps_kmp("ababaca") << endl;
    return 0;
}
