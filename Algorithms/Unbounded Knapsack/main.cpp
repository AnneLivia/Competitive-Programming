#include <iostream>
#include <vector>

using namespace std;

// The unbounded version of knapsack means that there are
// an unbounded (infinite) number of each item available
// So, given a knapsack with capacity W, pack as many items
// into the knapsack such that the total values of items packed is maximized.
// Since I can never exhaust any item because there are an unbounded supply of items
// the traditional way to solve knapsack problem 1-0 cannot be used here.

class UnboundedKnapsack {
private:
    vector<int>duration, points;
    int numberEvents, timeAvailable;
public:
    UnboundedKnapsack(int numberEvents, int timeAvailable) : numberEvents(numberEvents), timeAvailable(timeAvailable) {}
    void addEvent(int duration, int points) {
        this->duration.push_back(duration);
        this->points.push_back(points);
    }

    int maximum() {
        vector<int>dp(this->timeAvailable + 1, 0);
        for (int i = 0; i <= this->timeAvailable; i++) {
            for(int j = 0; j < this->numberEvents; j++) { // All events are available
                if(duration[j] <= i) { // If the time now respects the total time, then:
                    // take maximum, the current one or, the points of the current event plus the other time that can be added
                    dp[i] = max(dp[i], dp[i - duration[j]] + points[j]);
                }
            }
        }

        return dp[this->timeAvailable];
    }
};

int main()
{

    UnboundedKnapsack uk(2,8);
    uk.addEvent(2,10);
    uk.addEvent(3,19);

    cout << uk.maximum() << endl;
    return 0;
}
