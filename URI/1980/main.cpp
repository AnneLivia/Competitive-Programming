#include <iostream>

using namespace std;
long long unsigned int fat (int n) {
    if(n == 0)
        return 1;
    else
        return n * fat(n - 1);
}
int main()
{
    string anagrama;
    while(true) {
        cin >> anagrama;
        if(anagrama == "0")
            break;
        else
            cout << fat(anagrama.length()) << endl;
    }
    return 0;
}
