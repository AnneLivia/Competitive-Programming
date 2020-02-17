#include <iostream>

using namespace std;

struct Point {
    int x, y;
};

struct Rectangle {
    Point corner1, corner2;
};

/*
    The idea is to check if there's no collision in terms of height or width.
    if there's no collision in height, even if there's width overlaps, the height itself
    shows separation between the rectangles. Same would happen to width.
    Example:
    Those two rectangles bellow have no collision in terms of y (width), but
    there's collision in terms of height (x). but since the y does not intercept,
    it's enough to return false to a collision.
    So to check if there's a collision, just do:
        (r1.x2 "end of r1 for height") < r2.x1 "start of r2 for height" or
        (r1.x1 "start of r1 for height") > r2.x2 "end of r2 for height"
            return false, there's no collision, even if y width intercepts
            that condition means that if the r1 starts after r2 ends
            or r1 ends before r2 starts, there's no overlap at all.

        in the case of the rectangles bellow, this condition would not be satisfied
        because the end of r1 (height) is not smaller than x1 in r2 neither
        start of r1 (height) is greater than x2 in r2.
        check width
        (r1.y2 "end width of r1") < r2.y1 "start of r2 (width)" or
        (r1.y1 "start width of r1") > r2.y2 "end of r2 (width)"
            return false, there's no collision, even if x height intercepts
        in the case of the rectangles bellow, this condition would be satisfied
        because the end of r1 is smaller than start(y1) of r2. which means that the r1 ends before the r2 starts
        even if there's a collision in terms of height, the width does not collide, so return false
        if this condition would not be satisfied, then it would have a collision in terms of width and height

    (x1,y1) ---------
            |       |       (x1,y1)
            |       |          ---------
            |       |          |       |
            ---------          |       |
                   (x2,y2)     |       |
                               ---------
                                       (x2,y2)
*/
bool isColliding(const Rectangle& r1, const Rectangle& r2) {
    // checking x collision (height)
    if ((r1.corner2.x < r2.corner1.x) ||
        (r1.corner1.x > r2.corner2.x))
        return false; // is not colliding in terms of height

    // checking y collision (width)
    if ((r1.corner2.y < r2.corner1.y) ||
        (r1.corner1.y > r2.corner2.y))
        return false;

    // it's colliding
    return true;
}

int main()
{
    Rectangle a1, a2;

    cin >> a1.corner1.x >> a1.corner1.y >> a1.corner2.x >> a1.corner2.y;
    cin >> a2.corner1.x >> a2.corner1.y >> a2.corner2.x >> a2.corner2.y;

    cout << isColliding(a1,a2) << endl;
    return 0;
}
