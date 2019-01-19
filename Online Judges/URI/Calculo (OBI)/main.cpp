#include <iostream>
#include <vector>

using namespace std;

// Falta terminar

ostream& operator <<(ostream& ostr, const vector<int>& v) {
    for(int i = 0; i < (int)v.size(); i++)
        ostr << v[i] << " ";
    return ostr;
}

int main()
{
    vector<int> n1, n2, n3, nibble, aux1,aux2;
    int tam1, tam2, n;
    cin >> tam1 >> tam2; // Reading the size of the arrays
    for ( int i = 0; i < tam1; i++) {
        cin >> n;
        n1.push_back(n); // Putting the values in the array 1
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
    // The operation is running bellow
    nibble.assign(tam1 + 1, 0);
    for ( int i = 0; i < tam1; i++) {
        if(n1[i] == 0 && n2[i] == 1 || n1[i] == 1 && n2[i] == 0 && nibble[i] == 0)
            n3.push_back(1);
        else if (n1[i] == 0 && n2[i] == 1 || n1[i] == 1 && n2[i] == 0 && nibble[i] == 1) {
            nibble[i + 1] = 1;
            n3.push_back(0);
        } else if (n1[i] == 0 && n2[i] == 0 && nibble[i] == 0)
            n3.push_back(0);
        else if (n1[i] == 1 && n2[i] == 1 && nibble[i] == 0) {
            n3.push_back(0);
            nibble[i + 1] = 1;
        } else if (n1[i] == 1 && n2[i] == 1 || n1[i] == 0 && n2[i] == 0 && nibble[i] == 1){
            n3.push_back(1);
            if(n1[i] == 1)
                nibble[i + 1] = 1;
        }
    }


    bool flag = true;
    for ( int i = 0; i < tam1; i++) {
        if(n3[i] == 1 && flag) {
            flag = false;
        }
        if(!flag)
            aux2.push_back(n3[i]);
    }
    // Inverting the n3, since is in the inverse order
    for ( int i = (int)aux2.size() - 1; i >= 0; i--) {
        aux1.push_back(aux2[i]);
    }

    cout << aux1 << endl;
    return 0;
}
