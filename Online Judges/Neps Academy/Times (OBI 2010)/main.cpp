#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main () {
    int n, t;
    cin >> n >> t;

    vector<pair<int, string> > student(n, {0, ""});
    vector<vector<string> >team(t, vector<string>());

    for (int i = 0; i < n; i++) {
        cin >> student[i].second >> student[i].first;
    }

    sort(student.rbegin(), student.rend());

    int j = 0;
    for (int i = 0; i < n; i++) {
        team[j].push_back(student[i].second);
        j++;
        if(j >= t)
            j = 0;
    }

    for (int i = 0; i < t; i++) {
        cout << "Time " << i + 1 << endl;
        sort(team[i].begin(), team[i].end());
        for (int j = 0; j < (int)team[i].size(); j++) {
            cout << team[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
}

