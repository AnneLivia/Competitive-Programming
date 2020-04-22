#include <iostream>
#include "circularlinkedlist.h"

using namespace std;

int main()
{
    Head *h = create();

    cout << "Is the list empty? " << isEmpty(h) << endl;
    cout << "Size:  " << listSize(h) << endl;

    insert_sorted(h, -1);
    insert_sorted(h, -4);
    insert_sorted(h, 2);
    insert_sorted(h, 4);
    insert_front(h, 3);
    // insert_back(h, -4);

    cout << "Showing elements: ";
    for(int i = 1; i <= listSize(h); i++) {
        cout << get_pos(h, i) << " ";
    }

    cout << endl;

    cout << "Is the list empty? " << isEmpty(h) << endl;
    cout << "Size:  " << listSize(h) << endl;


    cout << "Back element: " << get_back(h) << endl;
    insert_front(h, 10);
    cout << "Showing elements: ";
    for(int i = 1; i <= listSize(h); i++) {
        cout << get_pos(h, i) << " ";
    }
    cout << endl;

    cout << "Front element: " << get_front(h) << endl;
    cout << "is there value -1? " << find_value(h, -1) << endl;
    cout << "is there value 9? " << find_value(h, 9) << endl;

    remove_value(h, 10);
    cout << "Front element: " << get_front(h) << endl;
    remove_back(h);
    cout << "Back element: " << get_back(h) << endl;
    insert_front(h, 11);
    insert_front(h, 12);
    insert_front(h, 13);
    insert_front(h, 14);
    remove_front(h);
    cout << "Showing elements: ";
    for(int i = 1; i <= listSize(h); i++) {
        cout << get_pos(h, i) << " ";
    }
    cout << endl;


    remove_pos(h, 3);

    cout << "Showing elements again: ";
    for(int i = 1; i <= listSize(h); i++) {
        cout << get_pos(h, i) << " ";
    }
    cout << endl;

    deleteList(h);

    cout << "Is the list empty now? " << isEmpty(h) << endl;
    cout << "Size now:  " << listSize(h) << endl;

    return 0;
}
