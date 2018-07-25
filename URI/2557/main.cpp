#include <iostream>

using namespace std;

int main()
{
    string expression, st1, st2, st3;
    long int num1, num2;
    bool first, sec;
    while(cin >> expression) {
        st1 = st2 = st3 = "";
        first = sec = false;
        for(int i = 0; i < (int)expression.size(); i++) {
            if(expression[i] != '+' && !first) {
                st1+=expression[i];
            } else if (expression[i] != '=' && !sec) {
                first = true;
                if(expression[i] != '+')
                    st2+=expression[i];
            } else {
                sec = true;
                if(expression[i] != '=')
                    st3+=expression[i];
            }
        }

        if(st1 == "R") {
            cout << stoi(st3) - stoi(st2) << endl;
        } else if (st2 == "L") {
            cout << stoi(st3) - stoi(st1) << endl;
        } else {
            cout << stoi(st1) + stoi(st2) << endl;
        }
    }
    return 0;
}
