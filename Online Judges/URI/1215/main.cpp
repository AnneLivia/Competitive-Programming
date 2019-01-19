#include <iostream>
#include <set>

using namespace std;

int main()
{
    string text, wo;
    set<string>word;

    while(getline(cin,text)) {
        wo = "";
        text+=' ';
        for(int i = 0; i < text.length(); i++) {
            if(isalpha(text[i]) && text[i] != ' ') {
                wo+=tolower(text[i]);
            } else {
                word.insert(wo);
                wo = "";
            }
        }
    }

    word.erase(word.begin());
    for(auto i : word) {
        cout << i << endl;
    }

    return 0;
}
