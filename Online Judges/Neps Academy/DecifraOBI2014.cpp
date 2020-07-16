#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<char>a(26, 'a');
    char c;
    string str = "";
    for (int i = 0; i < 26; i++) {
        cin >> a[i];
    }

    while(cin >> c) {
        str+=a[(int)(c - 'a')];
        if (cin.peek() == '\n')
           break;
        
    }  

    cout << str << endl;
    return 0;  
}
