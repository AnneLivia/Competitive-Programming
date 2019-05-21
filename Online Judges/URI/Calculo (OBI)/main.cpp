#include <iostream>
#include <vector>

using namespace std;


ostream& operator <<(ostream& ostr, const vector<int>& v) {
    for(int i = 0; i < (int)v.size(); i++)
        ostr << v[i] << " ";
    return ostr;
}

int main()
{

    int tam1, tam2, n;
    vector<int>n1, n2, n3, aux1, aux2, nibble;

    cin >> tam1 >> tam2;

    for ( int i = 0; i < tam1; i++) {
        cin >> n;
        n1.push_back(n);
    }

    for ( int i = 0; i < tam2; i++) {
        cin >> n;
        n2.push_back(n); // Putting the values in the array 2
    }

    if(tam1 < tam2) {
        for ( int i = tam1; i < tam2; i++) {
            n1.push_back(0); // Putting 0 in the right side of the array if this is less than the second one
        }
        tam1 = tam2;
    }
    if(tam2 < tam1) {
        for ( int i = tam2; i < tam1; i++) {
            n2.push_back(0); // Same as above
        }
        tam2 = tam1;
    }

    // The above loop is to invert the number typed, because of the operation that occurs from the right to left.
    for ( int i = tam1 - 1; i >= 0; i--) {
        aux1.push_back(n1[i]);
        aux2.push_back(n2[i]);
    }

    n1 = aux1;
    n2 = aux2;

    aux1.clear(); aux2.clear();

    n3.assign(tam1, 0);
    // The operation is running bellow
    nibble.assign(tam1 + 1, 0);

    for (int i = 0; i < tam1; i++) {
        if((n1[i] == 1 && n2[i] == 0) || (n1[i] == 0 && n2[i] == 1)) {
            if(nibble[i] != 1) {
                n3[i] = 1;
            } else {
                nibble[i + 1] = 1;
            }
        } else if (n1[i] == 0 && n2[i] == 0) {
            if(nibble[i] == 1)
                n3[i] = 1;
        } else {
            if(nibble[i] == 1) {
                n3[i] = 1;
            }
            nibble[i + 1] = 1;
        }
    }



    int i;
    for ( i = 0; i < (int)n3.size(); i++) {
        if(n3[i] != 0)
            break;
    }

    for (int j = (int)n3.size() - 1; j >= i; j--) {
        aux1.push_back(n3[j]);
    }

    cout << aux1 <<  endl;
    return 0;
}
