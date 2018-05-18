#include <iostream>

using namespace std;

bool isdiagonal(int x1, int y1, int x2, int y2) {
    // The subtraction of x1 and x2 is the same as y1 and y2, that's the distance
    // Relation in between diagonals. the abs number;
    if(abs(x1 - x2) == abs(y1 - y2))
        return true;
    else
        return false;
}

int main()
{
    int x1, y1, x2, y2, moves;
    while(true) {
        moves = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1+x2+y1+y2 == 0)
            break;
        // If it's in the same line
        if(x1 == x2 && y1 == y2)
            moves = 0;
        // Same line, diagonal or column
        else if (x1 == x2 || y1 == y2 || isdiagonal(x1,y1,x2,y2))
            moves = 1;
        else // In case the coordinate that i want is in another position
            moves = 2;
        cout << moves << endl;
    }
    return 0;
}
