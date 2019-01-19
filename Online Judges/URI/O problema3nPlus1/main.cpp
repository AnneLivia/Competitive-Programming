#include <iostream>

using namespace std;

int problem(int n) {
    static int cont = 0;
    if(n == 1)
        return cont;
    cont++;
    if(n % 2 == 0)
        problem(n/2);
    else
        problem(3 * n + 1);

}
int main()
{
    int n;
    cin >> n;
    cout << problem(n) << endl;
    return 0;
}
