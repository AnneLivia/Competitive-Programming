#include <iostream>

using namespace std;

int main()
{
    string s, aux;
    int first = 0, n = 0;
    while(getline(cin, s)) {
        aux = "";

        for(int i = 0; i < (int)s.size(); i++) {
            if(s[i] == '\"' && !first) {
                aux+="``";
                first = 1;
            } else if (s[i] == '\"' && first) {
                aux+="\'\'";
                first = 0;
            } else {
                aux+=s[i];
            }
        }
        cout << aux <<  endl;
    }
    return 0;
}
