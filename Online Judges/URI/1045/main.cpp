#include <iostream>

using namespace std;

int main()
{
    double v[3];
    int aux;
    cin >> v[0] >> v[1] >> v[2];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j < 3; j++)
        {
            if(v[i] < v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }

    }

    if(!(v[0] >= v[1] + v[2])) {

        if((v[0]*v[0]) == (v[1] * v[1]) + (v[2] * v[2]))
            cout << "TRIANGULO RETANGULO\n";
        if((v[0]*v[0]) > (v[1] * v[1]) + (v[2] * v[2]))
            cout << "TRIANGULO OBTUSANGULO\n";
        if((v[0]*v[0]) < (v[1] * v[1]) + (v[2] * v[2]))
            cout << "TRIANGULO ACUTANGULO\n";
        if(v[0] == v[1] && v[1] == v[2])
            cout << "TRIANGULO EQUILATERO\n";
        if(v[0] == v[1] && v[1] != v[2] || v[0] == v[2] && v[2] != v[1] || v[1] == v[2] && v[2] != v[0])
            cout << "TRIANGULO ISOSCELES\n";
    } else {
        cout << "NAO FORMA TRIANGULO\n";
    }
    return 0;
}
