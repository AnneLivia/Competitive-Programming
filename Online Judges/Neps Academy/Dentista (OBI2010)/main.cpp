#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct consulta {
    int inicio, termino;
};

int main()
{
    int n;

    cin >> n;

    vector<consulta>con(n, {0,0});
    for (int i = 0; i < n; i++) {
        cin >> con[i].inicio >> con[i].termino;
    }
    sort(con.begin(), con.end(), [](const consulta& c1, const consulta& c2){
        return (c1.termino < c2.termino);
    });

    int qtd = 1, ende = con[0].termino;
    for (int i = 1; i < (int)con.size(); i++) {
        if(con[i].inicio >= ende) {
            ende = con[i].termino;
            qtd++;
        }
    }

    cout << qtd << endl;
    return 0;
}
