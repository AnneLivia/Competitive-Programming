#include <iostream>

using namespace std;

int main()
{
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    /*
        Euclidean distance is a straight line between two points
        shortest path between two points (diagonal map).

        Manhattan distance is not likely to euclidean, suppose there are many
        blocks and some paths, it cannot go through the blocks,
        it must go through the paths;

        Running through streets must be used the Manhattan distance

    */
    cout << abs(x1 - x2) + abs(y1-y2) << endl;
    return 0;
}
