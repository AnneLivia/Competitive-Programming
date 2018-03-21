#include <iostream>

using namespace std;

int main()
{
    int A[3], B[3];
    for ( int i = 0; i < 3; i++) {
        cin >> A[i];
    }
    for ( int i = 0; i < 3; i++) {
        cin >> B[i];
    }

    if(A[0] > B[0])
        cout << "A\n";
    else {
        if(A[0] == B[0]) {
            if(A[1] > B[1])
                cout << "A\n";
            else {
                if(A[1] == B[1]) {
                    if(A[2] > B[2]) {
                        cout << "A\n";
                    } else {
                        cout << "B\n";
                    }
                } else {
                    cout << "B\n";
                }
            }
        } else {
            cout << "B\n";
        }
    }
    return 0;
}
