#include <iostream>

using namespace std;

int main()
{
    string n, digit;
    char d;

    while(1) {
        digit = "";
        cin >> d >> n;
        if(d == '0' && n == "0")
            break;
        for(int i = 0; i < n.length(); i++) {
            if(n[i] != d) {
                digit+=n[i];
            }
        }
        if(digit == "")
            digit = "0";
        else {
            int cont = 0;
            for(int i = 0; i < digit.length(); i++) {
                if(digit[i] == '0')
                    cont++;
            }
            int j = 0;
            bool flag = false;
            string aux = "";
            if(cont == digit.length())
                digit = "0";
            else if (cont != 0) {
                for(int i = 0; i < digit.length(); i++) {
                    if(digit[i] != '0')
                    {
                        flag = true;
                    }
                    if(flag) {
                        aux += digit[i];
                    }
                }
                digit = aux;
            }
        }
        cout << digit << endl;
    }
    return 0;
}
