#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string expression;
    bool okay;
    int t;
    cin >> t;
    getchar();
    while(t--) {
        okay= true;
        stack<char>character;
        cin >> expression;
        getchar();

        for ( int i = 0; i < (int)expression.size(); i++) {
            if(expression[i] == '(') {
                character.push(expression[i]);
            } else if (expression[i] == '{') {
                character.push(expression[i]);
            } else if (expression[i] == '[') {
                character.push(expression[i]);
            } else if (!character.empty()) {
                if(character.top() == '(' && expression[i] == ')') {
                    character.pop();
                } else if (character.top() == '{' && expression[i] == '}') {
                    character.pop();
                } else if (character.top() == '[' && expression[i] == ']') {
                    character.pop();
                } else {
                    okay = false;
                    break;
                }
            } else {
                okay = false;
                break;
            }
        }
        if(character.empty() && okay) {
            cout << "S\n";
        } else {
            cout << "N\n";
        }
    }
    return 0;
}
