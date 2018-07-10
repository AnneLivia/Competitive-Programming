#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int qtdv, id, idsS, cs;
    vector<pair<int,int>>vid;

    while(cin >> qtdv >> id) {
        vid.clear();
        while(qtdv--) {
            cin >> idsS >> cs;
            vid.push_back(make_pair(idsS,cs));
        }
        cs = 0;
        for ( int i = 0; i < (int)vid.size(); i++) {
            if(vid[i].first == id) {
                if(vid[i].second == 0)
                    cs++;
            }
        }
        cout << cs << endl;
    }
    return 0;
}
