#include <iostream>

using namespace std;

int main()
{
    int n1, n2, result;
    char op;
    string aux;
    cin >> n1 >> op >> n2;
    aux = to_string(n1);
    for ( int i = 0; i < (int)aux.size(); i++) {
        if(aux[i] == '7')
            aux[i] = '0';
    }

    n1 = stoi(aux);

    aux = to_string(n2);
    for ( int i = 0; i < (int)aux.size(); i++) {
        if(aux[i] == '7')
            aux[i] = '0';
    }

    n2 = stoi(aux);

    if(op == '+')
        result = n1 + n2;
    else
        result = n1 * n2;

    aux = to_string(result);
    for ( int i = 0; i < (int)aux.size(); i++) {
        if(aux[i] == '7')
            aux[i] = '0';
    }

    result = stoi(aux);

    cout << result << endl;
    return 0;
}
