#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    string s, aux;
    char c;
    int counter, qtd;
    while(getline(cin,s) && s != "*") {
        istringstream split(s);
        counter = qtd = 0;
        while(split >> aux) {
            qtd++;
            if(counter == 0) {
                c = tolower(aux[0]);
            }
            if(tolower(aux[0]) == c)
                counter++;
        }
        if(counter == qtd)
            cout << "Y\n";
        else
            cout << "N\n";
    }
    return 0;
}
