#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int qt, qtA, time, sum;
    char l;
    string judge;
    map<char,int>s;
    map<char,bool>ok;
    while(cin >> qt && qt) {
        qtA = sum = 0;
        s.clear();
        ok.clear();
        while(qt--) {
            cin >> l >> time >> judge;
            if(s.find(l) != s.end() && judge != "correct") {
                s.at(l)+=20;
            } else if (s.find(l) != s.end() && judge == "correct") {
                if(!ok.at(l)) {
                    s.at(l)+=time;
                    qtA++;
                }
                ok.at(l) = true;

            } else {
                if(judge == "correct") {
                    s.insert(make_pair(l,time));
                    qtA++;
                    ok.insert(make_pair(l,true));
                } else {
                    s.insert(make_pair(l,20));
                    ok.insert(make_pair(l,false));
                }
            }
        }
        if(qtA != 0) {
            for(auto it = s.begin(); it != s.end(); it++) {
                if(ok.at(it->first))
                    sum+=it->second;
            }
        }

        cout << qtA << " " << sum << endl;
    }
    return 0;
}
