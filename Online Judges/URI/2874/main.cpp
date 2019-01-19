#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int qtd, sum;
    string bin, word;
    while(cin >> qtd) {
        word = "";
        while(qtd--) {
            cin >> bin;
            sum = 0;
            for(int i = bin.size() - 1, j = 0; i >= 0; i--, j++) {
                if(bin[i] == '1')
                    sum+=pow(2.0, j);
            }
            word+=(char)sum;
        }
        cout << word << endl;
    }
    return 0;
}
