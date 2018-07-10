#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string s;

    while(cin >> s) {
        stack <char> myStack;
        bool success = true;
        for ( int i = 0; i < s.size(); i++) {
            if(s[i] == '(')
                myStack.push(s[i]);
            else if(s[i] == ')') {
                if(myStack.empty()){
                    success = false;
                } else {
                    myStack.pop();
                }
            }
        }
        if(myStack.empty() && success)
            cout << "correct\n";
        else
            cout << "Incorrect\n";
    }

    return 0;
}
