#include <iostream>
#include "binary_tree.h"
using namespace std;

int main()
{

    BinaryTree *bt = create_tree();

    delete_tree(bt);
    return 0;
}
