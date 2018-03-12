#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string sentence, word;
    bool c, o1, b, o2, l;

    while(cin >> sentence) {
        vector<string>words;
        word = "";
        sentence+='-';
        for(int i = 0; i < (int)sentence.length(); i++) {
            if(sentence[i] != '-') {
                word+=sentence[i];
            } else {
                words.push_back(word);
                word = "";
            }
        }
        c = o1 = b = o2 = l = false;

        if(tolower(words[0][0]) == 'c' || tolower(words[0][words[0].size() - 1]) == 'c')
            c = true;
        if(tolower(words[1][0]) == 'o' || tolower(words[1][words[1].size() - 1]) == 'o')
            o1 = true;
        if(tolower(words[2][0]) == 'b' || tolower(words[2][words[2].size() - 1]) == 'b')
            b = true;
        if(tolower(words[3][0]) == 'o' || tolower(words[3][words[3].size() - 1]) == 'o')
            o2 = true;
        if(tolower(words[4][0]) == 'l' || tolower(words[4][words[4].size() - 1]) == 'l')
            l = true;

        if(c && o1 && b && o2 && l)
            cout << "GRACE HOPPER\n";
        else
            cout << "BUG\n";
    }
    return 0;
}
