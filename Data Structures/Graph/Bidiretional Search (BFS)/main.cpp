#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

/*
    Bidirectional Search is a search strategy that different from a simple
    search, where we run a DFS or BFS, or other search algorithm from the source
    vertex, here the goal is to run the search algorithm from both directions. Source and
    Goal, simultaneously until they find a middle vertex that belongs to both of them, that is,
    when the two graphs intersect.
    So it basically run in two steps:
        -> Forward search: source vertex to goal vertex
        -> Backward search: goal vertex to source vertex
    Bidirectional search replaces single search graph(which is likely to grow exponentially) with two smaller sub graphs.
     bidirectional search can be guided by a heuristic estimate of remaining distance from source to goal and vice versa
    for finding shortest path possible.

    Heuristic is a technique designed for solving problem more quickly when classic methods are too slow, or for finding an
    approximate solution when classic methods fail to find any exact solution.
    The heuristic function is a way to inform the search about the direction to a goal.
    It provides an informed way to guess which neighbor of a node will lead to a goal.

    Bidirectional Approach is in many case faster the simple single search, so it reduces the amount of required exploration.
    We can use bidirectional approach when:
        both source and goal vertexes are unique and completely defined.
        The branching factor is exactly the same in both directions.
            branching factor is the number of children at each node, the outDegree.
            If this value is not uniform, an average branching factor can be calculated.
            a static branching factor only happens in perfect binary trees.
            Average branching factor happens in most cases.
    Time and space complexity is O(b ^ (d/2)) where, b is the branching factor and d is the distance goal

    We can use any search algorithm on both sides, Bidirectional search is more of a strategy than a fixed algorithm.
    Using BFS on both sides is the most popular option as it guarantees an optimal path.

    ""
        Information from: http://theoryofprogramming.com/2018/01/21/bidirectional-search/
        Bidirectional search must be used only when your goal is well defined. Eg. for a Rubik’s cube, your goal is to
        fill each side with one color, which is your goal and your current configuration of cube is your source state.
        We could use Bidirectional search in this scenario. But in chess, your goal is to checkmate the other player,
        but a checkmate can happen in thousands of ways.
        Bidirectional search isn't feasible in chess.

        Bidirectional search using BFS needs the edge weights to be same or non-existent. So usually Bidirectional
        BFS is used in undirected unweighted graphs.
    ""
*/

class Graph {
private:
    vector<vector<int> > gra;
    int nv;
public:
    Graph(int nv) : nv(nv) {
        gra.assign(nv, vector<int>());
    }

    void addEdge(int x, int y) {
        this->gra[x].push_back(y);
        this->gra[y].push_back(x);
    }

    void BFS(queue<int>& q, vector<bool>& vi, vector<int>& parent) {

        int vertex = q.front();

        q.pop();
        // run through each adjacent
        for (int i = 0; i < (int)gra[vertex].size(); i++) {
            // if not visited
            if(!vi[gra[vertex][i]]) {
                // mark as visited
                vi[gra[vertex][i]] = true;
                // set the parent of the current node
                parent[gra[vertex][i]] = vertex;
                // insert that in the stack
                q.push(gra[vertex][i]);
            }
        }
    }

    int checkIntersection(vector<bool>& viS, vector<bool>& viG) {
        // to check if both search intersects, we can simply check
        // if both arrays that keep track of which vertex has been visited
        // has a specific vertex that was visited by both.
        for (int i = 0; i < this->nv; i++) {
            // run through each vertex of the graph
            if(viS[i] && viG[i]) {
                return i; // if vertex i was already visited by both directions backwards and forward, return node
            }
        }

        return -1; // otherwise, return -1, to specify that there's any intersection yet
    }

    void showPath(int& source, int& goal, int& intersection, vector<int>& pathS, vector<int>& pathG) {
        // saving path, first from source to intersected node
        vector<int>fullPath;
        fullPath.push_back(intersection);
        int aux = intersection;
        // while it hasn't reached the source node which has parent as -1
        while(aux != source) {
            // moving to the next node (moving backwards from intersection to source
            aux = pathS[aux];
            fullPath.push_back(aux);
        }
        reverse(fullPath.begin(), fullPath.end());
        // inserting now in the stack the path from intersection to goal vertex
        aux = intersection;
        while(aux != goal) {
            // moving to the next node
            aux = pathG[aux];
            fullPath.push_back(aux);
        }
        // showing path
        for (int i = 0; i < (int)fullPath.size(); i++) {
            cout << fullPath[i] << " ";
        }
        cout << endl;
    }

    int bidirectional_search_BFS(int source, int goal) {
        // vectors to keep track of visited vertexes from both directions
        // source and goal vertex, and set them to false
        vector<bool>viS(this->nv, false);
        vector<bool>viG(this->nv, false);

        // creating vectors to save path (parents of each node)
        vector<int>pathS(this->nv, 0);
        vector<int>pathG(this->nv, 0);

        // queue to use in the BFS for both source and goal vertex
        queue<int> qs, qg;

        // insert source vertex at the queue and mark that as visited
        viS[source] = true;
        qs.push(source);
        pathS[source] = -1; // parent of source is -1

        // insert source vertex at the queue and mark that as visited
        viG[goal] = true;
        qg.push(goal);
        pathG[goal] = -1; // parent of source is -1

        // run search simultaneously until it intersects
        while(!qs.empty() && !qg.empty()) {
            // run DFS in both directions
            BFS(qs, viS, pathS); // source: forward direction
            BFS(qg, viG, pathG); // goal: backward direction

            // check if they intersects, if it returns a number different of -1, it
            // intersect at the node returned by the function
            int intersection = checkIntersection(viS, viG);
            if(intersection != -1) {
                cout << "From " << source << " to " << goal << ", intersection is: " << intersection << endl;
                cout << "Path is: ";
                showPath(source, goal, intersection, pathS, pathG);
                return 1; // finished search
            }
        }
        return 0; // error, there's not any path
    }
};
int main()
{
    Graph g(15);
    g.addEdge(0, 4);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 8);
    g.addEdge(8, 9);
    g.addEdge(8, 10);
    g.addEdge(9, 11);
    g.addEdge(9, 12);
    g.addEdge(10, 13);
    g.addEdge(10, 14);
    if(!g.bidirectional_search_BFS(0, 14))
        cout << "There is not any path from 0 to 14" << endl;
    return 0;
}
