#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string cpf;
    bool multidig1, multidig2;
    int lastDigit1, lastDigit2, counter1,counter2;
    while(cin >> cpf) {
        vector<int>number;
        multidig1 = multidig2 = false;
        lastDigit1 = lastDigit2 = 0;
        for(int i = 0; i < cpf.length(); i++) {
            if(isalnum(cpf[i])) {
                number.push_back((cpf[i] - '0'));
            }
        }
        counter1 = 1;
        counter2 = 9;
        for(vector<int>::iterator it = number.begin(); it < number.end() - 2; it++) {
            lastDigit1 += *it * counter1++;
            lastDigit2 += *it * counter2--;
        }
        if((lastDigit1 % 11) == 10)
        {
            if(number[number.size() - 2] == 0)
                multidig1 = true;
        } else {
            if(number[number.size() - 2] == lastDigit1 % 11)
                multidig1 = true;
        }

        if((lastDigit2 % 11) == 10)
        {
            if(number[number.size() - 1] == 0)
                multidig2 = true;
        } else {
            if(number[number.size() - 1] == lastDigit2 % 11)
                multidig2 = true;
        }
        if(multidig1 && multidig2)
            cout << "CPF valido\n";
        else
            cout << "CPF invalido\n";
    }
    return 0;
}
