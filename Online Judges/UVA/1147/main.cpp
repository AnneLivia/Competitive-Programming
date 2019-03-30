#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > v;
int hx, hy;

int checkMoveHorse() {
	// for position 2 up and 1 left or right, or 2 down and 1 left or right
	// check if pawns can attack horse there,
	// it can be either left or right position on the diagonal
	int mov = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((v[i][j] == 2 || v[i][j] == 3) && (i != hx && j != hy) &&
               !((i + 1 <= 7 && j - 1 >= 0 && (v[i + 1][j - 1] == 1 || v[i + 1][j - 1] == 3)) ||
                (i + 1 <= 7 && j + 1 <= 7 && (v[i + 1][j + 1] == 1 || v[i + 1][j + 1] == 3)))) {
				mov++;
            }
		}
	}
	return mov;
}


int main()
{
	int n, t = 1;
	char c;

	while (cin >> n && n) {
		cin >> c;
		hx = n - 1, hy = ((int)c - 'a');
		v.assign(8, vector<int>(8, 0));
		v[n - 1][((int)c - 'a')] = 2; // horse
		for (int i = 0; i < 8; i++) {
			cin >> n >> c;
			v[n - 1][((int)c - 'a')] = 1; // pawns
		}

		if (hx - 2 >= 0 && hy - 1 >= 0)
			v[hx - 2][hy - 1] = (v[hx - 2][hy - 1] == 1) ? 3 : 2;
		if (hx - 2 >= 0 && hy + 1 <= 7)
			v[hx - 2][hy + 1] = (v[hx - 2][hy + 1] == 1) ? 3 : 2;
		if (hx + 2 <= 7 && hy - 1 >= 0)
			v[hx + 2][hy - 1] = (v[hx + 2][hy - 1]) == 1 ? 3 : 2;
		if (hx + 2 <= 7 && hy + 1 <= 7)
		   v[hx + 2][hy + 1] = (v[hx + 2][hy + 1]) == 1 ? 3 : 2;

		if (hx - 1 >= 0 && hy - 2 >= 0)
			v[hx - 1][hy - 2] = (v[hx - 1][hy - 2]) == 1 ? 3 : 2;
		if (hx + 1 <= 7 && hy - 2 >= 0)
			v[hx + 1][hy - 2] = (v[hx + 1][hy - 2]) == 1 ? 3 : 2;
		if (hx - 1 >= 0 && hy + 2 <= 7)
			v[hx - 1][hy + 2] = (v[hx - 1][hy + 2]) == 1 ? 3 : 2;
		if (hx + 1 <= 7 && hy + 2 <= 7)
		    v[hx + 1][hy + 2] = (v[hx + 1][hy + 2]) == 1 ? 3 : 2;


		cout << "Caso de Teste #" << t++ << ": " << checkMoveHorse() << " movimento(s)." << endl;
	}
	return 0;
}

