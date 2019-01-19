#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string n1, n2;
    float n1f, n2f, cutoff;
    while(cin >> n1 >> n2) {
        n1f = stof(n1);
        n2f = n1f - (int)n1f;
        cutoff = stof(n2);

        if(n2f >= cutoff) {
            n1f++;
        }
        cout << (int)n1f << endl;
    }
    return 0;
}
