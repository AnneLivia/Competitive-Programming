#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string expression;

    while(cin >> expression)
    {
        stack <char> validation;
        bool answer = true;
        for ( int i = 0; i < expression.size(); i++) {
            if(expression[i] == '(')
                validation.push(expression[i]);
            else {
                if(expression[i] == ')') {
                    if(validation.empty())
                        answer = false;
                    else
                        validation.pop();
                }
            }
        }
        if(validation.empty() && answer)
            cout << "correct\n";
        else
            cout << "incorrect\n";
    }

    return 0;
}
