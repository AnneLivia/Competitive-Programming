#include <iostream>

using namespace std;

int main()
{
    int n, number, stop = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int cont = 1;
        cin >> number;
        while(cont <= number)
        {
            if(number % cont == 0)
            {
                stop++;
            }
            cont++;
        }
        if(stop == 2)
            cout << number << " eh primo\n";
        else
            cout << number << " nao eh primo\n";

        stop = 0;
    }

    return 0;
}
