#include <iostream>

using namespace std;

int main()
{
    int A, B, C;
    while(cin >> A >> B >> C) {
        if(A != B && A != C)
            cout << "A\n";
        else if (B != A && B != C)
            cout << "B\n";
        else if(C != A && C != B)
            cout << "C\n";
        else
            cout << "*\n";
    }
    return 0;
}
