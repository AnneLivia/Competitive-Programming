#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

ostream& operator << (ostream& ostr, const vector<char>& v) {
    for (auto i : v) {
        ostr << i << " ";
    }
    return ostr;
}
int main()
{
    map<char, int> mc = {
        {'A', 1},
        {'2', 2},
        {'3', 3},
        {'4', 4},
        {'5', 5},
        {'6', 6},
        {'7', 7},
        {'8', 8},
        {'9', 9},
        {'D', 10},
        {'Q', 11},
        {'J', 12},
        {'K', 13},
    };

    int n, k;

    cin >> n >> k;

    vector<vector<char> > cards(n + 1, vector<char>(4, ' '));

    int isWithCoringa = k, justReceived = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> cards[i][j];
        }
    }


    cards[k].push_back('C');

    while(true) {
        vector<int>winner;
        for (int i = 1; i < (int)cards.size(); i++) {
            if((int)cards[i].size() == 4) {
                int contt = 0;
                for(int j = 0; j < (int)cards[i].size() - 1; j++) {
                    if(cards[i][j] == cards[i][j + 1]) {
                        contt++;
                    }
                }
                if(contt == 3) {
                    winner.push_back(i);
                }
            }
        }

        if((int)winner.size() > 0) {
            sort(winner.begin(), winner.end());
            cout << winner[0] << endl;
            break;
        }

        if(isWithCoringa == k && !justReceived) {
            auto it = find(cards[k].begin(), cards[k].end(), 'C');
            if(it != cards[k].end()) {
                cards[k].erase(it);
            }
            if(k == n) {
                cards[1].push_back('C');
                isWithCoringa = 1;
            } else {
                cards[k + 1].push_back('C');
                isWithCoringa = k + 1;
            }
            justReceived = 1;
        } else {
            map<char, int> cont;
            if((int)cards[k].size() > 0) {
                for (int i = 0; i < (int)cards[k].size(); i++) {
                    if(cards[k][i] != 'C') {
                        if(cont.find(cards[k][i]) != cont.end()) {
                            cont.at(cards[k][i])++;
                        } else {
                            cont.insert({cards[k][i], 1});
                        }
                    }
                }


                int minimum = 10000000;
                char car = 'A';
                for(auto i : cont) {
                    if(i.second < minimum) {
                        minimum = i.second;
                        car = i.first;
                    } else if (i.second == minimum) {
                        if(mc.at(i.first) < mc.at(car)) {
                            minimum = i.second;
                            car = i.first;
                        }
                    }

                }
                cards[k].erase(find(cards[k].begin(), cards[k].end(), car));

                if(k == n) {
                    cards[1].push_back(car);
                } else {
                    cards[k + 1].push_back(car);
                }
                justReceived = 0;
            }
        }

        k++;
        if(k > n) {
            k = 1;
        }
    }
    return 0;
}
