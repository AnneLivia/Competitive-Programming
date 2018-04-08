#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int,int>no;
    int n,qtd;
    cin >> qtd;
    while(qtd--) {
        cin >> n;
        if(no.find(n) != no.end()) {
            no.at(n)+=1;
        } else {
            no.insert(make_pair(n,1));
        }
    }

    int maior = 0;
    map<int,int>::iterator it, aux;
    for ( it = no.begin(); it != no.end(); it++) {
        if(it->second >= maior) {
          maior = it->second;

          aux = it;
        }
    }

    cout << aux->first << endl;
    return 0;
}
