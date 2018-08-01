#include <iostream>
#include "binary_tree.h"
using namespace std;

int main()
{
    /*
        Binary tree values

                  2
            4           3
        1       2    9      13
    */
    BinaryTree *bt = create_tree();

    inserting(bt,2);
    inserting(bt,4);
    inserting(bt,3);
    inserting(bt,1);
    inserting(bt,2);
    inserting(bt,9);
    inserting(bt,13);

    // 2, 4, 1, 2, 3, 9, 13
    cout << "Pre-order: \n";
    pre_order(bt);

    delete_node(bt,13);

    cout << "\nIn-order: \n";
    in_order(bt);

    cout << "\nPost-order: \n";
    post_order(bt);

    int n;

    int tam;

    cout << "\n\nDeleting elements: ";
    while(!isEmpty(bt)) {
        post_order(bt);
        tam = nodeNumbers(bt);
        cout << "Number to delete: ";
        cin >> n;
        delete_node(bt, n);
        if(nodeNumbers(bt) == tam)
            cout << "\n" << n << " it's not in the tree!\n";
    }
    delete_tree(bt);
    return 0;
}
