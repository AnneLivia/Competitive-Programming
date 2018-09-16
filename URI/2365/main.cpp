#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct Guess {
    string name;
    vector<string>game;
    int points = 0;
    void setGame(string g) {
        game.push_back(g);
    }

};

struct Winner {
    string name;
    int point;
};

bool compare(const Winner& w1, const Winner& w2) {
    if(w1.point > w2.point)
        return true;
    else if (w1.point == w2.point) {
        return (w1.name < w2.name);
    }
    return false;
}

int main()
{
    int n, p; // participants and number of games
    string s;
    vector<Guess> g;
    vector<Winner>w;
    vector<string> r;
    Guess aux;
    Winner waux;
    while(cin >> n >> p && n && p) {
        g.clear();
        cin.ignore();
        r.clear();
        w.clear();
        while(n--) {
            getline(cin,s);
            aux.name = s;
            aux.game.clear();
            for(int i = 0; i < p; i++) {
                getline(cin,s);
                aux.setGame(s);
            }
            g.push_back(aux);
        }

        for(int i = 0; i < p; i++) {
            getline(cin,s);
            r.push_back(s);
        }

        int res1, res2, bet1, bet2, cont;
        string aux;
        for(int i = 0; i < (int)g.size(); i++) {
            for(int j = 0; j < (int)g[i].game.size(); j++) {
                cont = 0;
                stringstream split1(r[j]);
                while(split1 >> aux) {
                    if(cont == 1)
                        res1 = stoi(aux);
                    if(cont == 3)
                        res2 = stoi(aux);
                    cont++;
                }

                cont = 0;

                stringstream split2(g[i].game[j]);
                while(split2 >> aux) {
                    if(cont == 1) {
                        bet1 = stoi(aux);
                    }

                    if(cont == 3)
                        bet2 = stoi(aux);
                    cont++;
                }

                if((bet1 == res1) && (bet2 == res2)) {
                    g[i].points+=10;
                } else if (((bet1 > bet2 && res1 > res2) || (bet1 < bet2 && res1 < res2) || (bet1 == bet2 && res1 == res2)) && (bet1 == res1 || bet2 == res2)) {
                    g[i].points+=7;
                } else if ((bet1 > bet2 && res1 > res2) || (bet1 < bet2 && res1 < res2) || (bet1 == bet2 && res1 == res2)) {
                    g[i].points+=5;
                } else if ((bet1 == res1) || (bet2 == res2)) {
                    g[i].points+=2;
                }

            }
            waux.name = g[i].name;
            waux.point = g[i].points;
            w.push_back(waux);
        }
        sort(w.begin(),w.end(),compare);
        for(int i = 0; i < (int)w.size(); i++)
            cout << w[i].name << " " << w[i].point << endl;
    }
    return 0;
}
