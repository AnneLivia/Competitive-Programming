#include <iostream>

using namespace std;

int main()
{
    unsigned int n1, n2,cont, aux1[9], aux2[9] = {0}, carry[9] = {0}, maior;

    while(true) {
        cont = 0;
        cin >> n1 >> n2;
        if(n1 == 0 && n2 == 0)
            break;
        int term1 = 0, term2 = 0;
        int j = 0;

        while(n1 > 0 || n2 > 0) {
            if(n1 > 0) {
                aux1[term1++] = n1 % 10;
                n1 = n1 / 10;
            }
            if(n2 > 0) {
                aux2[term2++] = n2 % 10;
                n2 = n2 / 10;
            }
            carry[j++] = 0;
        }
        if(term1 > term2) {
            maior = term1;
            while(term2 < 9)
                aux2[term2++] = 0;
         } else {
            maior = term2;
             while(term1 < 9)
                aux1[term1++] = 0;
         }
        j = 1;
        for ( int i = 0; i < maior; i++){
            if(aux1[i] + aux2[i] + carry[j - 1] >= 10) {
                carry[j] = (aux1[i] + aux2[i] + carry[j - 1]) / 10;
                cont++;
            }
            j++;
        }

        if(cont == 0) {
            cout << "No carry operation.\n";
        } else if(cont == 1) {
            cout << "1 carry operation.\n";
        } else {
            cout << cont << " carry operations.\n";
        }
    }
    return 0;
}
