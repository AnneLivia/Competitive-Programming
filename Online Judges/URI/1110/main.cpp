#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int>sta, discard;
    int n, aux;

    while(cin >> n && n != 0) {

        sta.clear();
        discard.clear();

        for(int i = n; i >= 1; i--) {
            sta.push_back(i);
        }

        while((int)sta.size() >= 2) {
            discard.push_back(sta.back());
            sta.pop_back();
            aux = sta.back();
            sta.pop_back();
            sta.push_front(aux);
        }

        cout << "Discarded cards:";
        for(int i = 0; i < (int)discard.size(); i++) {
            if(i != 0) {
                cout << ", ";
            } else {
                cout << " ";
            }
            cout << discard.at(i);
        }

        cout << "\nRemaining card: " << sta.back() << endl;
    }
    return 0;
}
