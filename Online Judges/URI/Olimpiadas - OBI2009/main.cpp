#include <iostream>
#include <algorithm>
#define MAXN 100

using namespace std;

struct Paises{
    int id, o, p, b;
    Paises(){
        o = p = b = 0;
    }
};

struct Modalidade {
    int o, p, b;
};

// Function to sort according to the medals
bool sortRank(Paises p1, Paises p2) {
    if(p1.o > p2.o)
        return true;
    else if(p1.o == p2.o) {
        if(p1.p > p2.p)
            return true;
        else if (p1.p == p2.p) {
            if(p1.b > p2.b)
                return true;
            else if (p1.b == p2.b) {
                if(p1.id < p2.id)
                    return true;
                else
                    return false;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    return false;
}

int main()
{
    int qtdp, qtdm, o, p, b, cont = 0;
    cin >> qtdp >> qtdm;
    Modalidade m[MAXN];
    Paises pa[MAXN];

    while(cont < qtdm) {
        cin >> o >> p >> b;
        m[cont].o = o;
        m[cont].p = p;
        m[cont].b = b;
        cont++;
    }

    // Specifying the id of each country starting from 1 to qtdp;
    cont = 0;
    while(cont < qtdp) {
        pa[cont].id = cont + 1;
        cont++;
    }

    // Inserting number of medals to each country
    cont = 0;
    while(cont < qtdm) {
       pa[m[cont].o - 1].o+=1;
       pa[m[cont].p - 1].p+=1;
       pa[m[cont].b - 1].b+=1;
       cont++;
    }

    sort(pa, pa + qtdp, sortRank);

    // Printing the result
    cont = 0;
    while(cont < qtdp) {
        if(cont != 0)
         cout << " ";
        cout << pa[cont].id;
        cont++;
    }

    return 0;
}
