#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word1, word2, word3;
    getline(cin,word1);
    getline(cin,word2);
    getline(cin,word3);

    if(word1.compare("vertebrado") == 0) {
        if(word2.compare("ave") == 0) {
            if(word3.compare("carnivoro") == 0)
                cout << "aguia\n";
            else if(word3.compare("onivoro") == 0)
                cout << "pomba\n";
        } else if (word2.compare("mamifero") == 0) {
            if (word3.compare("onivoro") == 0)
                cout << "homem\n";
            else if(word3.compare("herbivoro") == 0)
                cout << "vaca\n";
        }
    } else if (word1.compare("invertebrado") == 0) {
        if(word2.compare("inseto") == 0) {
            if(word3.compare("hematofago") == 0)
                cout << "pulga\n";
            else if(word3.compare("herbivoro") == 0)
                cout << "lagarta\n";
        } else if (word2.compare("anelideo") == 0) {
            if (word3.compare("hematofago") == 0)
                cout << "sanguessuga\n";
            else if(word3.compare("onivoro") == 0)
                cout << "minhoca\n";
        }
    }
    return 0;
}
