#include <iostream>
#include <map>

using namespace std;

int main() {
    map<char, string> ma {
        {'a', "2"},
        {'b', "22"},
        {'c', "222"},
        {'d', "3"},
        {'e', "33"},
        {'f', "333"},
        {'g', "4"},
        {'h', "44"},
        {'i', "444"},
        {'j', "5"},
        {'k', "55"},
        {'l', "555"},
        {'m', "6"},
        {'n', "66"},
        {'o', "666"},
        {'p', "7"},
        {'q', "77"},
        {'r', "777"},
        {'s', "7777"},
        {'t', "8"},
        {'u', "88"},
        {'v', "888"},
        {'w', "9"},
        {'x', "99"},
        {'y', "999"},
        {'z', "9999"},
        {' ', "0"}
    };

    int t;
    cin >> t;

    string word, answer, previous;

    getchar();

    while(t--) {
        getline(cin, word);
        answer = "", previous = "";
        for (int i = 0; i < (int)word.size(); i++) {
            if (word[i] == toupper(word[i]) && word[i] != ' ') {
                answer+="#"+ma.at(tolower(word[i]));
            } else {
                if (previous[(int)previous.size() - 1] == ma.at(word[i])[0] &&
                    word[i] != ' ')
                    answer+="*";
                if (word[i] == ' ' && previous == " ")
                    continue;
                answer+=ma.at(word[i]);
            }
            if (word[i] != ' ')
                previous = ma.at(tolower(word[i]));
            else
                previous = " ";
        }
        cout << answer << endl;
    }

    return 0;
}
