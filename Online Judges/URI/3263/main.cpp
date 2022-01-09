#include <iostream>

using namespace std;

int main()
{
    int n, equals = 0, cont = 0;
    string string1, string2;
    cin >> n;
    cin >> string1 >> string2;

    // check if it is going to be equal or different from first string
    if (n % 2 == 0)
        equals = 1;

    for (int i = 0; i < (int)string1.size(); i++) {
        if (equals) {
            if (string1[i] == string2[i]) {
                cont++;
            }
        } else {
            if (string1[i] != string2[i]) {
                cont++;
            }
        }
    }

    if (cont == (int)string1.size()) {
        cout << "Deletion succeeded\n";
    }  else {
        cout << "Deletion failed\n";
    }

    return 0;
}
