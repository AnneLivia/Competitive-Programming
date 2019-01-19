#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int alma,almi,qtd,h;
    vector<int>alp;
    while(cin >> qtd >> almi >> alma) {
        alp.clear();
        while(qtd--) {
            cin >> h;
            if(h >= almi && h <= alma)
                alp.push_back(h);
        }

        cout << (int)alp.size() << endl;
    }
    return 0;
}
