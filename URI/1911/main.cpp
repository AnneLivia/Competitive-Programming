#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n;
    string one, two;
    map<string,string>na;
    int f, cerro;
    while(1) {
        na.clear();
        f = cerro = 0;
        cin >> n;
        if(n == 0)
            break;
        while(n--) {
            cin >> one >> two;
            na.insert(make_pair(one,two));
        }
        cin >> n;
        while(n--) {
            cin >> one >> two;
            cerro = 0;
            for(int i = 0; i < na.at(one).length(); i++) {
                if(na.at(one)[i] != two[i])
                    cerro++;
            }
            if(cerro > 1)
                f++;
        }
        cout << f << endl;
    }
    return 0;
}
