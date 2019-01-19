#include <iostream>
#include <set>

using namespace std;

int main()
{
    int cteste;
    string products, word;
    cin >> cteste;
    cin.ignore();
    while(cteste--) {
        set<string>listSMarket;
        word = "";
        getline(cin,products);
        products+=' ';
        for(int i = 0; i < (int)products.length(); i++) {
            if(products[i] != ' ')
                word+=products[i];
            else {
                listSMarket.insert(word);
                word = "";
            }
        }

        int cont = 0;
        for(auto i = listSMarket.begin(); i != listSMarket.end(); i++) {
            cout << *i;
            if(cont < (listSMarket.size() - 1)) {
                cout << " ";
                cont++;
            }
        }
        cout << endl;
    }

    return 0;
}
