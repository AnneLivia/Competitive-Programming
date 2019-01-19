#include <iostream>


using namespace std;


int euclides(int n1, int n2) {
    if(n1 % n2 == 0)
        return n2;
    return euclides(n2,n1%n2);
}

int main()
{

    int t, n1, n2, v;
    cin >> t;
    while(t--) {
        cin >> n1 >> n2;
        v = euclides(n1,n2);
        cout << v << endl;
    }
    return 0;
}
