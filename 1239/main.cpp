#include <iostream>
#include <string>

using namespace std;

int main()
{
    string text, resp;
    bool hasJa, AstJa;
    while(getline(cin,text)) {
        hasJa = AstJa = false; resp = "";
        for ( int i = 0; i < (int)text.size(); i++) {
            if(text[i] == '*') {
                if(AstJa) {
                    resp+="</b>";
                    AstJa = false;
                } else {
                    resp+="<b>";
                    AstJa = true;
                }
            } else if (text[i] == '_') {
                if(hasJa) {
                    resp+="</i>";
                    hasJa = false;
                } else {
                    resp+="<i>";
                    hasJa = true;
                }
            } else {
                resp+=text[i];
            }
        }
        cout << resp << endl;
    }
    return 0;
}
