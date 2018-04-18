#include <iostream>

using namespace std;

int main()
{
    string frase;
    while(getline(cin,frase)) {
        bool first = true;
        for ( int i = 0; i < (int)frase.size(); i++) {
            if(frase[i] != ',' && first)
                cout << frase[i];
            else {
                if(first)
                    cout << endl;
                first = false;
                if(frase[i] != ',')
                    cout << frase[i];
            }
        }
        cout << endl;
    }
    return 0;
}
