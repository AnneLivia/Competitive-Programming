#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cfloat> // to use FLT_MAX (maximum number of float, it will be used as the infinity value for the A* algorithm)
#include <chrono>
#include <limits>
#include <algorithm>
#include <thread>
#include <iomanip>

using namespace std;

/*
	A* Search: is one of the best techniques used in path-finding and graph transversal
	That algorithm runs in the worst case in O(|E|).
	The A* is an extension of Dijkstra.
	This algorithm uses a heuristic which associates an estimate of the lowest cost path from this node
	to the goal node, such that this estimate is never greater than the actual cost.

	This algorithm can be used in games, for path-finding, such as PAC MAN.

	For this algorithm we have some variables which are used to perform some operation every time a new node is
	added, F = G + H, where f is the total cost of the node, g is the distance between the current node and the start node, and h is the heuristic
	(estimated distance from the current node to the end node).
	We use the value of F to pick a node that has a best change of getting to the goal node.

	Dijkstra keep search without know which path to follow, so it calculates the paths for all of them
	Whereas the A* prioritizes the node that has the best chance to reach the end.

	A* is a modification of Dijkstra's Algorithm that is optimized for a single destination. Dijkstra's
	Algorithm can find paths to all locations; A* finds paths to one location, or the closest of several
	locations. It prioritizes paths that seem to be leading closer to a goal.

	A heuristic is like a educated guess that guides the search for a solution to the problem.
	One heuristic is admissible when it does not overestimate a distance, it can underestimate sometimes.

	So A* is a modified version of Dijkstra's Algorithm that uses a heuristic function to guide its order of path exploration
	Suppose we are looking for paths from start vertex a to c, any intermediate vertex b has two costs:
		- The known (exact) cost from the start vertex a to b.
		- The heuristic (estimated) cost from b to the end vertex c.
	Idea: run Dijkstra's Algorithm, but use this priority in the PQ.
	priority(b) = cost(a,b) + Heuristic(b,c)
	chooses to explore paths with lower estimated cost

	Heuristics can be calculated as: abs(p1.x - p2.x) + abs(p1.y - p2.y)
	The idea: dequeue/explore neighbors with lower (cost + heuristic)

	From Stanford material:
		At one extreme, if h(n) is 0, then only g(n) plays a role, and A* turns into Dijkstra's Algorithm, which is guaranteed to find a shortest path.
		If h(n) is always lower than (or equal to) the cost of moving from n to the goal, then A* is guaranteed to find a shortest path. The lower h(n) is,
		the more node A* expands, making it slower.
		If h(n) is sometimes greater than the cost of moving from n to the goal, then A* is not guaranteed to find a shortest path, but it can run faster.
		At the other extreme, if h(n) is very high relative to g(n), then only h(n) plays a role, and A* turns into Greedy Best-First-Search.
	What is heuristic search?
		A heuristic search is a technique to solve a problem faster than classic methods
		or to find an approximate solution when classic methods cannot.
		This is often used when we want to trade one that guarantees completeness, accuracy, precision, optimality, for speed.
		At each branching step, it evaluates the available information and makes a decision on which branch to follow
		The Heuristic is any device that is often effective but will not guarantee work in every case.
		So why do we need heuristics? One reason is to produce, in a reasonable amount of time, a solution that is good enough for the problem in question.
		Most problems are exponential. Heuristic Search let us reduce this to a rather polynomial number.
		We use this in AI because we can put it to use in situations where we can't find known algorithms.

	Heuristic search techniques in AI:
		They are divided into two categories:
			Directed Techniques and Weak techniques
		Directed heuristic search techniques:
			Also called blind search, uniformed search, and blind control strategy.
			These aren't always possible since they demand much time or memory.
			They search the entire state space for a solution and use an arbitrary ordering of operations.
			Examples of these are Breadth First Search (BFS) and Depth First Search (DFS).
		Weak Heuristic Search Techniques in AI:
			Other names for these are Informed Search, Heuristic Search, and Heuristic Control Strategy.
			These are effective if applied correctly to the right types of tasks and usually demand domain-specific information.
			We need this extra information to compute preference among child nodes to explore and expand.
			Each node has a heuristic function associated with it.
			Examples are Best First Search (BFS) and A*, Bidirectional Search, Tabu Search, Hill Climbing, Beam Search, Constraint Satisfaction Problems.
	-- the word "heuristic" has a very specific meaning. A heuristic is a function that estimates how close a state is to a goal
*/


/*
	Consider a square grid having many obstacles and we are given a starting cell and a target cell.
	We want to reach the target cell (if possible) from the starting cell as quickly as possible.
*/

// store to keep track of x and y coordinates, it could be used a simple pair structure
struct Cell {
	int x, y;
	// creating operator overloading to facilitate the comparison between two cells
	bool operator == (const Cell& c2) {
		return (this->x == c2.x && this->y == c2.y);
	}
};

// structure to store information as the algorithm run
struct InfoCell {
	int parentx, parenty;
	float h, f, g;
	// h is the heuristic, g is the cost to move from one cell to another and f is the sum of f and g
	// in the case of this algorithm, the cost of g is 1, each cell has cost of 1, it doesn't have any other weight
};

class Grid {
private:
	vector<vector<int> > grid;
	int nCells = 0;
public:
	Grid(int nCells) : nCells(nCells) {
		grid.assign(this->nCells, vector<int>(this->nCells, 0));

		// get number of obstacles randomly
		int nObstacles = 1 + rand() % nCells * 2;
		this->initializeGridRandomly(nObstacles);
	}

	void insertObstacle(Cell c) {
		this->grid[c.x][c.y] = 1;
	}

	void removeObstacle(Cell c) {
		this->grid[c.x][c.y] = 0;
	}

	void initializeGridRandomly(int nObstacles) {
		for (int i = 0; i < nObstacles; i++) {
			// generate random x and random y
			int x, y;
			do {
                x = rand() % this->nCells;
                y = rand() % this->nCells;
            } while(this->grid[x][y]);
			this->grid[x][y] = 1;
		}
	}

	void removeAllObstacles() {
		this->grid.assign(this->nCells, vector<int>(this->nCells, 0));
	}

	// --------------------------------------------------------------------------------------------------------------------------------------------------

	// function to calculate the heuristics
	float heuristicManhattan(Cell source, Cell goal) {
		// it takes the sum of the absolute values of the differences of the coordinates
		// example: x = (a,b), and y = (c,d), then Manhattan distance between x and y is abs(a - c) + abs(b - d).
		// The standard heuristic for a square grid, it's good when we want to move in four directions (up, down, left and right).
		//
		return abs(source.x - goal.x) + abs(source.x - goal.x);
	}

	// function to calculate the heuristics
	float heuristicDiagonal(Cell source, Cell goal) {
		// it takes the maximum absolute value of differences in the goal's x and y coordinates and the source's x and y coordinates respectively
		// example: x = (a,b), and y = (c,d), then Diagonal distance between x and y is max{abs{a - c},abs{b - d}).
		// We use it when we are allowed to move in eight directions only (similar to a move of a King in Chess)
		return max(abs(source.x - goal.x), abs(source.y - goal.y));
	}

	// function to calculate the heuristics
	float heuristicEuclidean(Cell source, Cell goal) {
		// it takes the square root of the sum of the squares of the differences of the coordinates
		// example: x = (a,b), and y = (c,d), then Euclidean distance between x and y is sqrt(((a - c)^2) + (abs(b - d))^2).
		// When to use this heuristic? When we are allowed to move in any directions.
		return sqrt(pow((source.x - goal.x), 2) + pow((source.y - goal.y), 2));
	}

	// --------------------------------------------------------------------------------------------------------------------------------------------------

	// show path taken from source to goal
	void showPath(Cell& source, Cell& goal, vector<Cell>& path) {
	    cout << setw(35) << " A* SEARCH ALGORITHM\n";
	    cout << " >> S is the source\n >> G is the Goal\n >> \'.\' is a free location\n >> \'#\' is a obstacle\n >> \'=\' path\n\n";
		for (int i = 0; i < this->nCells; i++) {
            cout << setw(10);
			for (int j = 0; j < this->nCells; j++) {
			    if(i == source.x && j == source.y) {
                    cout << " S ";
			    } else if (i == goal.x && j == goal.y) {
                    cout << " G ";
			    } else if (this->grid[i][j]) {
					cout << " # ";
				} else if (find_if(path.begin(), path.end(), [&](Cell& c) -> bool {return (c.x == i && c.y == j);}) != path.end()) {
                    cout << " = ";
				} else {
                    cout << " . ";
				}
			}
			cout << endl;
		}
	}

    // version two, without final path
	void showPath(vector<vector<bool> >& visitedCells, Cell& source, Cell& goal) {
	    cout << setw(35) << " A* SEARCH ALGORITHM\n";
	    cout << " >> S is the source\n >> G is the Goal\n >> \'.\' is a free location\n >> \'#\' is a obstacle\n >> \'=\' path\n\n";
		for (int i = 0; i < this->nCells; i++) {
            cout << setw(10);
			for (int j = 0; j < this->nCells; j++) {
			    if(i == source.x && j == source.y) {
                    cout << " S ";
			    } else if (i == goal.x && j == goal.y) {
                    cout << " G ";
			    } else if (visitedCells[i][j]) {
					cout << " = ";
				} else if (this->grid[i][j]) {
					cout << " # ";
				} else {
                    cout << " . ";
				}
			}
			cout << endl;
		}
	}

	void tracePath(vector<vector<InfoCell> >& dist, Cell& source, Cell& goal) {
        vector<Cell>path;
        int i = goal.x;
        int j = goal.y;
        while(!(dist[i][j].parentx == i && dist[i][j].parenty == j)) {
            path.push_back({i,j});
            // cannot update directly because of the i and j variable, if it change, it will be get a wrong position
            int tempX = dist[i][j].parentx;
            int tempY = dist[i][j].parenty;
            i = tempX;
            j = tempY;
        }

        this->showPath(source, goal, path);
	}

	// Dijkstra is a special case of A* Search Algorithm, where h = 0 for all nodes.

	bool AStarAlgorithm(Cell source, Cell goal) {
	    // in case source and goal is obstacle, remove those obstacles from grid
	    removeObstacle(source);
	    removeObstacle(goal);
		// create a vector to keep track of the information of the cells and initialize it with INF to all of them
		vector<vector<InfoCell> > dist(this->nCells, vector<InfoCell>(this->nCells, {-1,-1, FLT_MAX,FLT_MAX,FLT_MAX}));
		// array to keep track of the cells that were already proceeded
		vector<vector<bool> > visitedCells(this->nCells, vector<bool>(this->nCells, false));

		// create a priority queue algorithm to save the value of F which is the heuristic plus the cost of move from one cell to another
		// and the coordinates x,y of the cell
		priority_queue<pair<float, pair<int, int> >, vector<pair<float, pair<int, int> > >, greater<pair<float, pair<int, int> > > > priority;
		// insert the source coordinate and initializes it with 0
		dist[source.x][source.y].f = dist[source.x][source.y].g = dist[source.x][source.y].h = 0.0;
		dist[source.x][source.y].parentx = source.x; dist[source.x][source.y].parenty = source.y;
		// insert in the queue
		priority.push({ dist[source.x][source.y].f, {source.x, source.y} });
		// while the priority queue is not empty, similar to Dijkstra, the loop is going to keep running
		while (!priority.empty()) {
			// get the values from the priority queue
			Cell coordinates = { priority.top().second.first, priority.top().second.second };
			// remove it from priority
			priority.pop();
			// mark the current coordinate as proceeded
			visitedCells[coordinates.x][coordinates.y] = true;

            // ---------------------------------------------------
			this->showPath(visitedCells, source, goal);
            this_thread::sleep_for(chrono::milliseconds(300));
            system("cls");
            // ---------------------------------------------------

			// check if the current position taken from priority is the destination
			if (coordinates == goal) {
				// show path on grid
				this->tracePath(dist, source, goal);
				return true;
			}

			// if it's not the goal, check all of the possible movements, in this case it's going to be considered only
			// up, down, left and right movements, so it's going to be used the Manhattan Heuristic
			// up = {i - 1, j}, down = {i + 1, j}, left = {i, j - 1}, right = {i, j + 1}
			int row[4] = { 1, -1, 0, 0 }, col[4] = { 0, 0, 1, -1 };
			// running through each one of the four movements to calculate its heuristics and insert it on the priority queue
			for (int i = 0; i < 4; i++) {
				// calculate movement for both x and y coordinates
				int moveRow = coordinates.x + row[i];
				int moveCol = coordinates.y + col[i];
				// check if movement is allowed, if it was not proceeded yet and if there's any obstacle in it
				if (moveRow >= 0 && moveRow < this->nCells && moveCol >= 0 && moveCol < this->nCells &&
					!visitedCells[moveRow][moveCol] && !this->grid[moveRow][moveCol]) {
					// in case the next possible position is the goal, stop.
                    if(moveRow == goal.x && moveCol == goal.y) {
                        dist[moveRow][moveCol].parentx = coordinates.x;
                        dist[moveRow][moveCol].parenty = coordinates.y;
                        this->tracePath(dist, source, goal);
                        return true;
                    }

					// calculate f, g, and h and check if the result is smaller than the current one in this cell
					float gValue = dist[coordinates.x][coordinates.y].g + 1.0; // assume the cost to go from one cell to another is 1
					float hValue = heuristicManhattan({ moveRow, moveCol }, goal); // calculate the new h value using the Manhattan
					float fValue = gValue + hValue; // f = g + h;

					// if f value is smaller than the f of the current position, update all of its informations to the new ones
					if (fValue < dist[moveRow][moveCol].f) {
						dist[moveRow][moveCol].g = gValue;
						dist[moveRow][moveCol].f = fValue;
						dist[moveRow][moveCol].h = hValue;
						dist[moveRow][moveCol].parentx = coordinates.x;
						dist[moveRow][moveCol].parenty = coordinates.y;

						// insert it on the priority queue
						priority.push({ dist[moveRow][moveCol].f, {moveRow, moveCol} });
					}
				}
			}
		}

        this->showPath(visitedCells, source, goal);
        cout << setw(40) << "\nit's not possible reach the goal\n";
		// if it gets here, it wasn't possible to get in the goal coordinates
		return false;
	}
};

int main()
{
	srand(time(NULL));
	int ok = 1;
	do {
        Grid g(10);
        g.AStarAlgorithm({ 0,0 }, { 9,9 });
        cin >> ok;
        system("cls");
	} while(ok);
	return 0;
}
