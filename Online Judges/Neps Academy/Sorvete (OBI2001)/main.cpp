#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int comp, n;
    cin >> comp >> n;
    vector<pair<int, int> > v(n, pair<int,int>());

    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), [](const pair<int,int>& v1, const pair<int,int>& v2) -> bool{
        return (v1.second  > v2.second);
    });


    vector<pair<int,int> >inter;
    // first I get the minimum start of the interval and the maximum end of the interval
    int me = v[0].first, ma = v[0].second;
    // then I check other intervals
    for (int i = 1; i < n; i++) {
        // if the start of one interval is less than the interval of the minimum one, It may not fit, but first:
        if(v[i].first < me) {
           // check if the end of the current interval is smaller than the minimum start so far, if it is:
           if(v[i].second < me) {
                // insert it on a array, since it does not fit
                inter.push_back({me, ma});
                // and update minimum start and maximum end with the values of the current interval, since it's going to check other interval
                me = v[i].first;
                ma = v[i].second;
            } else {
                // otherwise, this interval fits, but the minimum start interval must be updated, since we've found a start smaller than the current minimum start
                me = v[i].first;
            }
        }
    }

    inter.push_back({me,ma});

    sort(inter.begin(), inter.end());

    for (int i = 0; i < (int)inter.size(); i++) {
        cout << inter[i].first << " " << inter[i].second << endl;
    }

    return 0;
}
