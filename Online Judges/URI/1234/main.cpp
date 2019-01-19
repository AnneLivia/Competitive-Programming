#include <iostream>
#include <string>


using namespace std;

int main()
{
    string sentence;
    bool cap = true;
    while(getline(cin,sentence)) {
        for ( int i = 0; i < sentence.length(); i++) {
            if(cap && sentence[i] != ' ') {
                if(sentence[i] != '1' && sentence[i] != '2' && sentence[i] != '3' && sentence[i] != '4' && sentence[i] != '5' && sentence[i] != '6' && sentence[i] != '7' && sentence[i] != '8' && sentence[i] != '9' && sentence[i] != '0') {
                    sentence[i] = toupper(sentence[i]);
                    cap = false;
                }
            } else if (sentence[i] != ' '){
                if(sentence[i] != '1' && sentence[i] != '2' && sentence[i] != '3' && sentence[i] != '4' && sentence[i] != '5' && sentence[i] != '6' && sentence[i] != '7' && sentence[i] != '8' && sentence[i] != '9' && sentence[i] != '0') {
                    sentence[i] = tolower(sentence[i]);
                    cap = true;
                }
            }
        }

        cout << sentence << endl;
        cap = true;
    }
    return 0;
}
