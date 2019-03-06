#ifndef BST_H
#define BST_H

#include <iostream>
#include <cstdlib>

/*
    A binary search tree is a node-based binary tree
    data structure which has the following properties.

    The left subtree of a node contains only node with keys lesser than or equal to the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key
    The left and right subtree each must also be a binary search tree

    Example:
              8
        3         10
    1      6          14
        4     7    13


    Some applications: binary search, analysis of algebraic expression: infix, prefix and postfix.

    Main operations:
    Insertion: worst case: O(n) not balanced tree

    Remotion: worst case: O(n) not balanced tree

    Consult: worst case: O(n) not balanced tree

    Example of a not balanced tree would be when there is many value in the left side and just one in the right side
*/

struct Node {
    int number;
    Node *left, *right;
};

typedef Node *BinaryTree;

// Creating and deleting tree
BinaryTree* create_tree();
void delete_node(Node *no);
void delete_tree(BinaryTree *bt);

// Tree informations
int isEmpty(BinaryTree *bt);
int nodeNumber(BinaryTree *bt);
int tree_height(BinaryTree *bt);

// Transversing tree
void in_order(BinaryTree *bt);
void pre_order(BinaryTree *bt);
void post_order(BinaryTree *bt);


// Insertion in a Binary search tree
int insert_value(BinaryTree *bt, int number);

// Delete a value in a binary search tree
int delete_value(BinaryTree *bt, int number); // Function responsible for search for the node to be removed
Node* remove_current(Node *current); // function responsible for treat each one of the 3 cases of remotion

// access elements
bool searchElement(BinaryTree* bt, int v);
bool searchElementUtil(Node *node, int v);

#endif // BST_H
