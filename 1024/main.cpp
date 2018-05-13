#include <iostream>

using namespace std;

int main()
{
    int t;
    string text;
    cin >> t;
    cin.ignore();
    while(t--) {
        getline(cin,text);
        for ( int i = 0; i < (int)text.size(); i++) {
            if(toupper(text[i]) >= 'A' && toupper(text[i]) <= 'Z')
                text[i]+=3;
        }
        string aux = "";
        for ( int i = (int)text.size() - 1; i >= 0; i--) {
            aux+=text[i];
        }
        text = aux;

        for ( int i = ((int)text.size() / 2); i <= (int)text.size(); i++) {
            text[i]-=1;
        }

        cout << text << endl;
    }
    return 0;
}
