#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string str1, str2;
    int cont = 0, k, qtd;
    cin >> str1 >> str2;

    for(int i = 0; i < str1.size() - str2.size() + 1; i++) {
        k = i;
        qtd = 0;
        for(int j = 0; j < (int)str2.size(); j++) {
            if(str1[k++] == str2[j])
                qtd++;
        }

        if(qtd == 0)
            cont++;
    }
    cout << cont << endl;
    return 0;
}
