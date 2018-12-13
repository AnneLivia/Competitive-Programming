#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Variable respectively: number of words, maximum lines per page, maximum chars per line
    // iterator variable, number of lines, numbers of pages, number of chars, number of spaces and number of words.
    int n, l, c, i, nl, np, nc, ns, qtdw;
    vector<string>v;
    string str;

    while(cin >> n >> l >> c) {

        v.clear();

        while(n--) {
            cin >> str;
            v.push_back(str);
        }

        i = nl = np = nc = ns = qtdw = 0;

        while(i < (int)v.size()) {
            qtdw++; // if amount of words is greater than one get space
            if(qtdw > 1)
                ns = qtdw - 2; // space is qtdw - 2
            if(((nc + (int)v[i].size() + ns) < c) || (nc == 0 && (int)v[i].size() == c)) {
                // if number of total char with the new word plus the total of space so far is less than the maximum char per line, or
                // in case the word is right exactly the amount of char and the number of chars so far is 0, to avoid infinite loop, okay.
                nc+=v[i].size(); // add new number of chars.
                i++; // go to the next word
                if(i == (int)v.size()) // if there's no next word, then add more one page, there are words left that won't be added
                    np++;
            } else {
                // if number of chars is greater using the current word, then, increment line
                nl++;
                if(nl == l) { // if line is equal to the maximum line per page, increment page
                    np++;
                    nl = 0; // line is now 0, to check again
                }
                ns = qtdw = nc = 0; // 0 to all other variables to count again
            }
        }
        cout << np << endl;
    }
    return 0;
}
