#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<char,int>comp = {
        {'W',64},{'H',32},{'Q',16},
        {'E',8},{'S',4},{'T',2},
        {'X',1}
    };
    string compasso;
    bool ja; int sum, qtd;
    while(cin >> compasso && compasso.compare("*") != 0) {
        ja = false; sum = 0; qtd = 0;
        for ( int i = 0; i < (int)compasso.size(); i++) {
            sum+=comp[compasso[i]];
            if(compasso[i] == '/') {
                if(sum == 64)
                    qtd++;
                sum = 0;
            }
        }
        cout << qtd << endl;
    }
    return 0;
}
