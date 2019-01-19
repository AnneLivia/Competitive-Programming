#include <iostream>
#include <list>

using namespace std;

int main()
{
    float nota, sumN = 0;
    int cont = 5;
    list<float>notas;

    while(cont--)
    {
        cin >> nota;
        notas.push_back(nota);
    }
    notas.sort();
    list<float>::iterator i = ++notas.begin();
    list<float>::iterator lastButOne = --notas.end();
    for(; i != lastButOne; i++) {
        sumN += *i;
    }

    cout.precision(1);
    cout.setf(ios::fixed);
    cout << sumN << endl;
    return 0;
}
