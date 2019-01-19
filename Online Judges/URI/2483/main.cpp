#include <iostream>

using namespace std;

int main()
{
    int n;
    string sentence = "Feliz nat";
    cin >> n;

    for ( int i = 0; i < n; i++) {
        sentence += 'a';
    }
    sentence+="l!";
    cout << sentence << endl;
    return 0;
}
