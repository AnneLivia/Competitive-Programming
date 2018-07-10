#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
// Maybe there's gonna be TLE
bool compare(vector<int>&v1, vector<int>&v2) {
    if(v1[2] < v2[2])
        return true;
    else if (v1[2] == v2[2]) {
        if(v1[1] < v2[1])
            return true;
        else if (v1[1] == v2[1]) {
            if(v1[0] < v2[0])
                return true;
            else
                return false;
        } else
            return false;
    } else {
        return false;
    }
}

int index(const vector<string>& auxStr, const vector<vector<int>>& d) {
    int ind, q = 0, ok = 0, i, j, value;
    string fulldate;
    for ( i = 0; i < (int)auxStr.size(); i++) {
        fulldate = "";
        for ( j = 0; j < (int)auxStr[i].size(); j++) {
            if(auxStr[i][j] != '/') {
                fulldate+=auxStr[i][j];
            } else {
                value = stoi(fulldate);
                if(value == d[0][q++]) {
                    ok++;
                }
                fulldate = "";
            }
        }
        if(ok == 3)
            ind = i;
        ok = 0;
    }
    return ind;
}

int main()
{
    int npeople, ndates, value, went;
    string fulldate;
    vector<vector<string>>date;
    vector<vector<int>> attended;
    vector<int>aux; // Auxiliary vector
    vector<vector<int>>auxInt; // Auxiliary vector
    vector<string>auxStr; // Auxiliary vector
    while(cin >> npeople >> ndates) {
        date.clear();
        attended.clear();
        auxInt.clear();

        while(ndates--) {
            auxStr.clear();
            cin >> fulldate;
            auxStr.push_back(fulldate);
            date.push_back(auxStr);
            aux.clear();
            int i = 0;
            while(i < npeople) {
                cin >> value; // Read who has appeared to the meet up
                aux.push_back(value);
                i++;
            }
            attended.push_back(aux);
        }
        auxStr.clear();
        for ( int i = 0; i < (int)date.size(); i++) {
            went = 0;

            for ( int j = 0; j < npeople; j++) {
                if(attended[i][j] == 1)
                    went++;
            }
            if(went == npeople) {
                auxStr.push_back(date[i][0]);
            }
        }

        if(auxStr.empty()) {
            cout << "Pizza antes de FdI\n";
        } else if ((int)auxStr.size() == 1)
            cout << auxStr[0] << endl;
        else {
            aux.clear();
            for ( int i = 0; i < (int)auxStr.size(); i++) {
                fulldate = "";
                auxStr[i]+="/";
                for ( int j = 0; j < (int)auxStr[i].size(); j++) {
                    if(auxStr[i][j] != '/') {
                        fulldate+=auxStr[i][j];
                    } else {
                        value = stoi(fulldate);
                        aux.push_back(value);
                        fulldate = "";
                    }
                }
                auxInt.push_back(aux);
                aux.clear();
            }
            sort(auxInt.begin(),auxInt.end(), compare);
            int ind = index(auxStr,auxInt);
            auxStr[ind].erase(auxStr[ind].size() - 1);
            cout << auxStr[ind] << endl;
        }
    }
    return 0;
}
