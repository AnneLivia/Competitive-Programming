#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, start = 0, cont = 0;
    cin >> n;
    vector<vector<char> >v;
    vector<char> aux1(4, ' ');

    v.push_back({'F', 'A', 'C', 'E'});

    while(n--) {
        for (int j = 0; j < 4; j++) {
            cin >> aux1[j];
        }
        int qtd = 0;
        // check if it matches
        vector<char> aux2 = v[(int)v.size() - 1]; // getting last element of the vector
        for (int j = 0, h = 3; j < 4; j++, h--) {
            if (aux1[j] == aux2[h]) { // h allows to run backwards
                qtd++; // count number of matches between last added word and current one
            }
        }

        // if it's equal to 4, then, pop last added to vector and count + 1
        if (qtd == 4) {
            v.pop_back(); // pop last word cause it was a match
            if (v.empty()) { // check if it's empty, because if that's the case, it must be added the word face again
                v.push_back({'F', 'A', 'C', 'E'}); // add again because it's empty
            }
            cont++; // count number of person who receives the award
        } else {
            // need to add new word
            v.push_back(aux1); // because the word added is not equal to the added before (in backward order)
        }
    }

    cout << cont << endl;


    return 0;
}
