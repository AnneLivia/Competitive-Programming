#include <iostream>
#include <queue>
#include <cstdlib>
#include <vector>

using namespace std;

int main() {

    int c, n, mm = 0, cont = 0;

    cin >> c >> n;

    vector<int>cc(c, 0);
    vector<pair<int,int> > co(n, {0,0});

    priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

    for (int i = 0; i < n; i++) {
        cin >> co[i].first >> co[i].second;
    }

    // store the index of the customers added to the queue
    int cn_current = 0;

    while(true) {

        if (cn_current == n && pq.empty()) {
            // if cn_current is equal to n it means the total number
            // of customers were added to the queue
            // but if the queue is not empty, it means they are still waiting
            // to be attend, otherwise, if all were added to queue and queue is empty
            // then there's no more costumer to check
            break;
        }

        // it starts from cn_current, because there's no need to start
        // from 0 the loop if the some customer were already added to queue
        for (int i = cn_current; i < n; i++) {
            // if the minute of someone get in the bank starts,
            // push it into the queue
            if(co[i].first == mm) {
                pq.push(co[i]);
                cn_current++;
            }
        }

        for (int i = 0; i < c; i++) {
            // remove customer, free cashier
            // if cc[i] is equal to mm, the moment for
            // the customer were attend by the cashier
            // 0 specify that the cashier is free for other customer
            if (cc[i] == mm)
                cc[i] = 0;

            // if there's a free cashier and there's customers waiting
            if (cc[i] == 0 && !pq.empty()) {
                // get it from priority queue and remove it
                pair<int, int> t = pq.top();
                pq.pop();
                // mm is the current minute, t.first is the moment the customer
                // has got to the bank, mm - t.first gives the time the customer
                // waited to be attended
                if ((mm - t.first) > 20)
                    cont++; // counting the number of customers had to wait more than 20 minutes

                // save in the current cashier the current minute + the time the current
                // customer is going to take to be attended by the cashier, that is the time
                // that probably other user must wait to be attended
                cc[i] = mm + t.second;
            }
        }

        // increase the minute
        mm++;
    }

    cout << cont << endl;
    return 0;
}

