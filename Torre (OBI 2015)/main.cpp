#include <iostream>
#include <cstring>
// Need fix
using namespace std;
int n, vet[1001][1001], sum = 0, visited[1001][1001] = {0};
void runningVert(int i, int j) {
    visited[i][j] = 1;
    sum += vet[i][j];
    if(i - 1 >= 0 && !visited[i - 1][j])
        runningVert(i-1,j);
    if(i + 1 < n && !visited[i + 1][j])
        runningVert(i + 1,j);
}

void runningHori(int i, int j) {
    visited[i][j] = 1;
    sum += vet[i][j];

    if(j - 1 >= 0 && !visited[i][j - 1])
        runningHori(i,j-1);
    if(j + 1 < n && !visited[i][j + 1])
        runningHori(i,j+1);
}

int main()
{

    cin >> n;
    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < n; j++) {
            cin >> vet[i][j];
        }
    }
    int maxSum = -1;
    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < n; j++) {
            runningHori(i,j);
            runningVert(i,j);
            memset(visited,0,sizeof(visited));
            sum -= 2 * vet[i][j];
            if(sum > maxSum)
                maxSum = sum;
            sum = 0;
        }
    }
    cout << maxSum << endl;
    return 0;
}
