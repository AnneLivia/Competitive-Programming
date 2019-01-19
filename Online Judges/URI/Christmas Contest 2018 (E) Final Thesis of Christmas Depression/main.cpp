#include <iostream>

using namespace std;

int main()
{
    int e, d;
    cin >> e >> d;

    if(e > d)
        cout << "Eu odeio a professora!\n";
    else {
        if((d - e) >= 3) {
            cout << "Muito bem! Apresenta antes do Natal!\n";
        } else {
            cout << "Parece o trabalho do meu filho!\n";
            d+=2;
            if(d <= 24)
                cout << "TCC Apresentado!\n";
            else
                cout << "Fail! Entao eh nataaaaal!\n";
        }
    }
    return 0;
}
