#include <iostream>

using namespace std;

int main()
{
    long n, soma;
    string number, value;
    cin >> n;
    while(n--) {
        soma = 0;
        number = "";
        cin >> value;
        value +="k";
        for(int i = 0; i < value.length() + 1; i++) {
            if(value[i] >= 48 && value[i] <= 57) {
                number +=value[i];
            } else {
                soma = soma + atoi(number.c_str());
                number = "";
            }
        }
        cout << soma << endl;
    }
    return 0;
}
