#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int> > v;
    int n;
    cin >> n;
    v.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    vector<int>lines(n, 0);
    vector<int>colls(n, 0);


    // check lines
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            lines[i]+= v[i][j];
            colls[i]+= v[j][i];
        }
    }

    int line, previousLine = -1, currentLine = -1;
    int col, previousCol = -1, currentCol = -1;

    for (int i = 0; i < n - 1; i++) {
        if(currentLine == -1) {
            currentLine = lines[i];
        } else {
            previousLine = currentLine;
            currentLine = lines[i];
        }

        if(lines[i] != lines[i + 1]) {
            if(currentLine != -1) {
                if(lines[i] == previousLine) {
                    line = i + 1;
                } else  {
                    line = i;
                }
            }
        }

        if(currentCol == -1) {
            currentCol = colls[i];
        } else {
            previousCol = currentCol;
            currentCol = colls[i];
        }

        if(colls[i] != colls[i + 1]) {
            if(currentCol != -1) {
                if(colls[i] == previousCol) {
                    col = i + 1;
                } else  {
                    col = i;
                }
            }
        }
    }

    int rightAnswer = 0, exactly;
    if(line - 1 >= 0) {
        rightAnswer = lines[line - 1];
    } else {
        rightAnswer = lines[line + 1];
    }

    exactly = abs(abs(lines[line] - v[line][col]) - rightAnswer);

    cout << exactly << " " << v[line][col] << endl;
    return 0;
}
