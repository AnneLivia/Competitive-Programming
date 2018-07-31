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
        free_node(v->left);
        free_node(v->right);
        free(no);
        no = nullptr;
    }
}
// Deleting tree
void delete_tree(BinaryTree *bt) {
    if(bt != nullptr) {
        free_node(*bt); // Free each node
        free(bt); // Free tree
    }
}
