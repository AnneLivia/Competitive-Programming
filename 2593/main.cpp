#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
// Must Finish
using namespace std;

struct ways {
    string word;
    int pos[100000], i;
    bool operator() (ways const& w) const {
        return (w.word.compare(word) == 0);
    }
};

int main()
{
    string text, word;
    vector<ways> k; ways aux, co;
    vector<string>w, ja;
    int qtdW, fP;
    getline(cin,text);
    cin >> qtdW;

    for ( int i = 0; i < qtdW; i++) {
        cin >> word;
        w.push_back(word);
    }
    text+=" ";
    word = "";
    for ( int i = 0; i < (int)text.size(); i++) {
        if(word == "")
            fP = i;
        if(text[i] != ' ') {
            word+=text[i];
        } else {
            if(find(w.begin(),w.end(),word) != w.end()) {
                if(find(ja.begin(),ja.end(),word) != ja.end()) {
                    co.word = word;
                    vector<ways>::iterator it = find_if(k.begin(),k.end(),ways(co));
                    if(it != k.end()) {
                        cout << it->i << endl;
                        it->i+=1;
                        it->pos[it->i] = fP;
                    }
                } else {
                    aux.word = word;
                    aux.i = 0;
                    aux.pos[aux.i] = fP;
                    k.push_back(aux);
                    ja.push_back(word);
                }
            }
            word = "";
        }
    }

    for ( int i = 0; i < (int)k.size(); i++) {
        cout << k[i].word << endl;
        cout << k[i].i << endl;
        for ( int j = 0; j < k[i].i; j++) {
            if(j != 0)
                cout << " ";
            cout << k[i].pos[j];
        }
        cout << endl;
    }


    return 0;
}
