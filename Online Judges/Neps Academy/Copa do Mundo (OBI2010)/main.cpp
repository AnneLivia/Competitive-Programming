#include <iostream>
#include <queue>

using namespace std;

int main() {

    queue<char> q;
    int a, b;
    char ta = 'A', tb = 'B';
    for (int i = 1; i <= 8; i++) {
        cin >> a >> b;
        if(a > b) {
            q.push(ta);
        } else {
            q.push(tb);
        }
        ta+=2; tb+=2;
    }

    while(q.size() > 1) {
        ta = q.front(); q.pop();
        tb = q.front(); q.pop();
        cin >> a >> b;
        if(a > b) {
            q.push(ta);
        } else {
            q.push(tb);
        }
    }

    cout << q.front() << endl;
    return 0;
}
