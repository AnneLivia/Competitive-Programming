#include <iostream>

using namespace std;

int main()
{
    int i, j, k, l, n, sum, t = 1;

    while(cin >> n && n) {
        sum = i = j = k = l = 0;
        while((sum + 50) <= n) {
            sum+=50;
            i++;
        }

        while((sum + 10) <= n) {
            sum+=10;
            j++;
        }

        while((sum + 5) <= n) {
            sum+=5;
            k++;
        }

        while((sum + 1) <= n) {
            sum+=1;
            l++;
        }
        cout << "Teste " << t++ << endl;
        cout << i << " " << j << " " << k << " " << l << endl << endl;
    }
    return 0;
}
