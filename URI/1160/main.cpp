#include <iostream>

using namespace std;

int main()
{
    int t, pA, pB, sumA, sumB;
    double g1, g2;

    cin >> t;

    for ( int i = 1; i <= t; i++)
    {
        int tAnos = 0;
        cin >> pA >> pB >> g1 >> g2;



        while(tAnos <= 100 && pA <= pB) {
            tAnos++;
            sumA = int((pA * g1) / 100);
            sumB = int((pB * g2) / 100);
            pA += sumA;
            pB += sumB;
        }

        if(tAnos > 100)
            cout << "Mais de 1 seculo.\n";
        else
            cout << tAnos << " anos.\n";

    }

    return 0;
}
