#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;
/*
    Pattern Search or String matching problem:
        A common problem in text editing, DNA sequence analysis and web crawling: find strings inside other
        strings. Suppose we have a text T consisting of an array of characters from
        some alphabet S. S might be just the set {1,0}, in which case it can form strings of binary digits.
        it can also be a set {A,C,T,G}, in which case it forms a DNA sequences.
        The string matching problem is this: given a smaller string P (the pattern) that we want to find occurrences
        of in T. If P occurs in T at shift i then P[j] = T[i+j] for all valid indexes i of P.
    String Matching Problem:
        String matching problem is the problem of finding all occurrences
        of a given pattern string in a text.
    String matching or searching algorithms try to find places where one or
    several strings (also called patterns) are found within a larger string (searched text)
    Some Applications:
        Text-editing software, web search engines, SPAM filters, natural language processing,
        computational biology (search a particular pattern in DNA sequence), feature detection
        in digital image, and many more.

    Information from geeks for geeks:
        The Pattern Searching algorithms are sometimes also referred to as String Searching
        Algorithms and are considered as a part of the String algorithms.
        These algorithms are useful in the case of searching a string within another string.
    Example:
        Text: AABAACAADAABAABA
        Pattern: AABA
        When some algorithm find a pattern, it will return the index where
        the string starts.
        -> A A B A A C A A D A A B A A B A
        -> A A B A, found one pattern that starts at 0
        -> A A B A A C A A D A A B A A B A
        -> . . . . - - - - - A A B A, found a pattern that starts at 9
        -> A A B A A C A A D A A B A A B A
        -> . . . . - - - - - . . . A A B A, found a pattern that starts at 12
    A naive solution to this consists of:
        -> Iterate through the text and if there's a mismatch we shift the pattern
        one step to the right.
            -> one loop will run the length of the text string minus the length of the pattern, so
            that we can compare each character of the pattern with each one of the text we're try to
            find the patterns.
            -> Another loop will go though all the length of the pattern and is going to be compared with
            the character at the iterator position of the first loop plus the iterator position of the second loop.
            -> if there's any character different, then we can just break the loop and check the size of the second
            iterator, if it's equal to the length of the pattern string, then we found a match, or we can create a boolean
            variable with true as default value, and then assign false in case the algorithm find a different character in
            the comparison (mismatch), in case it doesn't found a mismatch, we print the first iterator position.

    Complexity O (n * m) where n is the length of the text, m is the length of the pattern we are looking for
    Since there can be a lot of mismatch, this algorithm is not so efficient.
    or  O(m*(n-m+1)).
*/

void patternSearch(string text, string pattern) {
    string copyText = "";
    for_each(text.begin(), text.end(), [&copyText](char& c) {
        copyText+=tolower(c);
    });
    // The text must be greater than the pattern.
    int sizeText = (int)text.size();
    int sizePattern = (int)pattern.size();

    // We go to sizeText - sizePatter, because we are going to compare
    // each character with of the pattern string with the text, if we would
    // go through all the size of the text, suppose we go to the last position of
    // the string, we would compare first character of the pattern with the last of the
    // text, but the second, third, ..., nth position of the pattern would be compared with nothing.
    for (int i = 0; i < sizeText - sizePattern + 1; i++) {
        // Now we can either use a iterator J, or we can use a boolean variable to check if there's a mismatch
        // int j = 0;
        bool mismatchPattern = true; // default value as true.
        // create a loop to slide through all the character of the patter string and the specifics one from the text
        // while (j < m && pattern[j] == text[j + i])
        //     j++;
        for (int j = 0; j < sizePattern; j++) {
            // if it's different, it has found a mismatch, so it's hasn't found a pattern
            if(tolower(pattern[j]) != tolower(text[i + j])) {
                mismatchPattern = false;
                break;
            }
        }
        // if (j == sizePattern)
        //      match at i;
        // if mismatchPattern is true, it's because it hasn't found a character that is different from the patter string
        if(mismatchPattern) {
            cout << "There's a match at " << i << endl;
            for (int j = 0; j < sizeText; j++) {
                if(j >= i && j < i + sizePattern) {
                    copyText[j] = (char)toupper(copyText[j]);
                }
            }
        }
    }
    cout << "\n\nText: " << text << endl;
    cout << "Pattern: " << pattern << endl;
    cout << "Result: " << copyText << endl;
}

int main()
{
    patternSearch("AAAAACTGGAGAGAGACCCTACACACTTTGGGGAGAC", "GAGAC");
    return 0;
}
