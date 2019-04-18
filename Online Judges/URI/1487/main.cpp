#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// Greedy algorithm
struct Event {
    int duration, point, div;
    bool operator < (const Event& e) {
        return this->div < e.div;
    }
};

class SixFlag {
private:
    vector<Event>events;
    int nEvents, timeAvailable;
public:
    SixFlag(int nEvents, int timeAvailable) : nEvents(nEvents), timeAvailable(timeAvailable){}
    void addEvent(int duration, int point) {
        events.push_back({duration, point, (point / duration)});
    }

    int maximumPoints() {
        int result = 0, i = 0;
        sort(events.rbegin(), events.rend());
        while(i < nEvents) {
            if(events[i].duration <= timeAvailable) {
                result+=events[i].point;
                timeAvailable-=events[i].duration;
            } else {
                i++;
            }
        }
        return result;
    }
};

int main()
{
    int n, t, p, d, i = 1;
    while(cin >> n >> t && n) {
        SixFlag sf(n,t);
        while(n--) {
            cin >> d >> p;
            sf.addEvent(d, p);
        }
        cout << "Instancia " << i++ << "\n";
        cout << sf.maximumPoints() << "\n\n";
    }
    return 0;
}
