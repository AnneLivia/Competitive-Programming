#include <iostream>

using namespace std;

int main()
{
    char phrase[35] = {"LIFE IS NOT A PROBLEM TO BE SOLVED"};
    int n;
    do {
        cin >> n;
    } while (n < 1 || n > 34);

    for (int i = 0; i < n; i++) {
        cout << phrase[i];
    }
    cout << endl;
    return 0;
}
