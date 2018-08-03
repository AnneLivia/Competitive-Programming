#include <iostream>
#include "bst.h"

using namespace std;

int main()
{
    BinaryTree *bt = create_tree();
    int n, tam;


    insert_value(bt,10);
    insert_value(bt,20);
    insert_value(bt,1);
    insert_value(bt,40);
    insert_value(bt,55);
    insert_value(bt,515);
    insert_value(bt,545);
    insert_value(bt,2);

    tam = nodeNumber(bt);

    pre_order(bt);
    cout << endl;
    while(!isEmpty(bt)) {
        cout << "Remove an element: ";
        cin >> n;
        delete_value(bt,n);
        if(nodeNumber(bt) == tam) {
            cout << n << " was not found!\n";
        }
        post_order(bt);
        cout << endl;
    }
    delete_tree(bt);
    return 0;
}
