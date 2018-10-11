#include <iostream>

using namespace std;

int main()
{
    char c;
    cin >> c;
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        cout << "Vowel\n";
    else
        cout << "Consonant\n";

    return 0;
}
