#include "binary_tree.h"

// Creating tree
BinaryTree* create_tree() {
    BinaryTree* bt = (BinaryTree *)malloc(sizeof(BinaryTree));
    if(bt != nullptr) {
        *bt = nullptr; // it's null yet
    }
    return bt;
}

// Deleting nodes
void free_node(Vertex* v) {
    if(v != nullptr) { // If exist element
        free_node(v->left);  // go through all left nodes recursively
        free_node(v->right); // go through all right nodes recursively
        free(v); // free node when reached all left and right nodes
        v = nullptr;
    }
}

// Deleting tree
void delete_tree(BinaryTree *bt) {
    if(bt != nullptr) {
        free_node(*bt); // Free each node
        free(bt); // Free tree
    }
}

// Is empty
int isEmpty(BinaryTree *bt) {
    if(bt == nullptr || *bt == nullptr) // If either of them are null, it is empty
        return true;
    return false;
}

// Number of nodes (vertex)
int nodeNumbers(BinaryTree *bt) {
    if(bt == nullptr || *bt == nullptr)
        return 0;
    // Number of nodes at the left and right
    int height_left = nodeNumbers(&((*bt)->left));
    int height_right = nodeNumbers(&((*bt)->right));

    return (height_left + height_right + 1); // Left + Right +  1, because of the "parent" node;
}

// Height of the tree
int tree_height(BinaryTree *bt) {
    if(bt == nullptr || *bt == nullptr)
        return 0; // Binary tree empty

    // Notation to agree with the parameter of the function
    // Address of the left and right vertex
    int height_left = tree_height(&((*bt)->left));
    int height_right = tree_height(&((*bt)->right));

    if(height_left > height_right) // If the height of the left side is greater than the right side, return the left + 1
        return (height_left + 1);
    else
        return (height_right + 1);

}
/*
Binary tree values:
                  2
            4           3
        1       2    9      13
*/

// Iterate a binary tree: pre-order: first root, left children, then right children
void pre_order(BinaryTree *bt) {

    if(bt != nullptr && *bt != nullptr) { // The binary tree exist and is not empty
        cout << (*bt)->number << endl; // Print the value in the node
        pre_order(&((*bt)->left)); // Left child
        pre_order(&((bt)->right)); // Right child
    }

    // 2, 4, 1, 2, 3, 9, 13
}

// Iterate a binary tree: in-order: left tree side, root, and then right tree
void in_order(BinaryTree *bt) {
    if(bt != nullptr && *bt != nullptr) {
        in_order(&((*bt)->left));
        cout << (*bt)->number << endl; // Print the value in the node
        in_order(&((*bt)->right));
    }

    // 1 4 2 2 9 3 13
}

// Iterate a binary tree: post-order: left child, right child and then root
void post_order(BinaryTree *bt) {

    // It's guaranteed that will be visited all children of a specific parent node
    if(bt != nullptr && *bt != nullptr) {
        post_order(&((*bt)->left));
        post_order(&((*bt)->right));
        cout << (*bt)->number << endl; // Print the value in the node
    }

    // 1 2 4 9 13 3 2
}
