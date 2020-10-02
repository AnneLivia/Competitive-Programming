#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    vector<int>v(100, 0);
    int n, cont = 0;

    for (int i = 0; i < 6; i++)
    {
        cin >> n;
        v[n] = 1;
    }
    
    for (int i = 0; i < 6; i++)
    {
        cin >> n;
        if (v[n])
            cont++;
    }
    
    switch(cont) {
        case 3 : cout << "terno\n";
            break;
        case 4 : cout << "quadra\n";
            break;
        case 5 : cout << "quina\n";
            break;
        case 6 : cout << "sena\n";
            break;
        default: cout << "azar\n";
    }
    
    return 0;  
}
