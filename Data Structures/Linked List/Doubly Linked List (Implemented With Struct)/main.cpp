#include <iostream>
#include "doublylinkedlist.h"

using namespace std;

int main()
{
    Head *h = create();
    int v;

    cout << "Is the list empty? " << isEmpty(h) << endl;
    cout << "Size:  " << listSize(h) << endl;

    /*
    cout << "Insert values, press Ctrl + Z to finish loop.\n\n";
    while(cin >> v) {
       if(insert_back(h, v))
            cout << "Added\n";
       else
            cout << "Error\n";
    }*/

    // inserting sorted

    insert_sorted(h, 1);
    insert_sorted(h, 2);
    insert_sorted(h, 3);

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
    cout << "is there value 8? " << find_value(h, 8) << endl;
    cout << "is there value 2? " << find_value(h, 2) << endl;

    remove_value(h, 10);
    cout << "Front element: " << get_front(h) << endl;
    remove_back(h);
    cout << "Back element: " << get_back(h) << endl;
    insert_front(h, 10);
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
