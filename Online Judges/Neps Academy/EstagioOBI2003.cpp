#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, t = 1, maximum;
    vector<pair<int, int> > p;
    while(cin >> n && n) {
        p.assign(n, {0,0});
        maximum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].first >> p[i].second;
            if (p[i].second > maximum)
                maximum = p[i].second;
        }
    
        cout << "Turma " << t++ << endl;
        int space = 0;
        for (int i = 0; i < n; i++)
        {
            if (p[i].second == maximum) {
                if (space)
                    cout << " ";
                cout << p[i].first;
                space = 1;
            } 
        }
        cout << "\n\n";
    }
    return 0;  
}
