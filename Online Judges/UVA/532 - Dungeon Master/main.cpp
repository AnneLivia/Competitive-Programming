#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
vector<vector<vector<char> > > dungeon;
int d, r, c;

int bfs(int di, int sr, int sc) {
	// minutes, coordinates, dimension, pair<row and col>
	queue<pair<int, pair<int, pii> > >q;
	vector<vector<vector<int> > > visited(d, vector<vector<int> >(r, vector<int>(c, 0)));

	// row, col and dimension
	vector<int>row = { -1,1,0,0,0,0 }, col = { 0,0,-1,1,0,0 }, dim = { 0,0,0,0,-1,1};

	q.push({ 0, {di, {sr,sc}} });

	while (!q.empty()) {
		int dime = q.front().second.first;
		pair<int, int>coord = q.front().second.second;
		int minutes = q.front().first;
		q.pop();
		if (dungeon[dime][coord.first][coord.second] == 'E')
			return minutes;
		if (!visited[dime][coord.first][coord.second]) {
			visited[dime][coord.first][coord.second] = 1;
			for (int i = 0; i < 6; i++) {
				int dd = dime + dim[i];
				int rr = coord.first + row[i];
				int cc = coord.second + col[i];

				if (dd < 0 || dd >= d ||
					rr < 0 || rr >= r ||
					cc < 0 || cc >= c)
					continue;
				if (!visited[dd][rr][cc] && dungeon[dd][rr][cc] != '#') {
					q.push({ minutes + 1, {dd, {rr, cc}} });
				}
			}
		}
	}
	return -1;
}

int main()
{
	int ds, rs, cs;

	while (cin >> d >> r >> c && d && r && c) {
		dungeon.assign(d, vector<vector<char> >(r, vector<char>(c, '.')));
		for (int di = 0; di < d; di++) {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					cin >> dungeon[di][i][j];
					if (dungeon[di][i][j] == 'S')
						ds = di, rs = i, cs = j;
				}
			}
		}
		int minutes = bfs(ds, rs, cs);
		if (minutes == -1)
			cout << "Trapped!\n";
		else
			cout << "Escaped in " << minutes << " minute(s).\n";
	}
	return 0;
}
