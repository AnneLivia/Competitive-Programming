#include <iostream>

using namespace std;

int main()
{
    string text;
    getline(cin,text);
    if(text.length() > 140) {
        cout << "MUTE\n";
    } else {
        cout << "TWEET\n";
    }
    return 0;
}
