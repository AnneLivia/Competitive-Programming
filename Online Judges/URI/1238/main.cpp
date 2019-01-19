#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n, tam, menor1, menor2;
    string word1, word2, formedWord;
    cin >> n;
    while(n--) {
        getchar();
        formedWord = "";
        cin >> word1 >> word2;
        if(word1.size() > word2.size()) {
            tam = word1.size();
            menor1 = 0;
            menor2 = word2.size();
        } else {
            tam = word2.size();
            menor1 = word1.size();
            menor2 = 0;
        }
        int j = 0;
        if(!menor1) {
            for ( int i = 0; i < tam; i++) {
                formedWord +=word1[i];
                if(j < word2.size())
                    formedWord +=word2[i];
                j++;
            }
        } else {
            for ( int i = 0; i < tam; i++) {
                if(j < word1.size())
                    formedWord +=word1[i];
                formedWord +=word2[i];
                j++;
            }
        }
        cout << formedWord << endl;
    }
    return 0;
}
