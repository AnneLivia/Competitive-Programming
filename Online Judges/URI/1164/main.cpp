#include <iostream>

using namespace std;

int main()
{
    int n, value;
    cin >> n;
    for (int i = 0 ; i < n ; i++ )
    {
        int cont = 1, sum = 0;

        cin >> value;
        while(cont < value)
        {
            if(value % cont == 0)
            {
                sum += cont;
            }
            cont++;
        }
        if(sum == value)
            cout << value << " eh perfeito\n";
        else
            cout << value << " nao eh perfeito\n";
    }

    return 0;
}
