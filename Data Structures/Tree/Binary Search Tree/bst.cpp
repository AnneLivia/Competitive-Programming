#include "bst.h"

using namespace std;

// Creating binary Tree
BinaryTree* create_tree() {
    BinaryTree* bt = (BinaryTree *)malloc(sizeof(BinaryTree));
    if(bt != nullptr) {
        *bt = nullptr;
    }
    return bt;
}

// Deleting nodes
void delete_node(Node *no) {
    if(no != nullptr) {
        delete_node(no->left);
        delete_node(no->right);
        free(no);
        no = nullptr;
    }
}

// Deleting Tree
void delete_tree(BinaryTree *bt) {
    if(bt != nullptr) {
        delete_node(*bt);
        free(bt);
        bt = nullptr;
    }
}

// Accessing tree informations
int isEmpty(BinaryTree *bt) {
    if(bt == nullptr || *bt == nullptr)
        return true;
    return false;
}

int nodeNumber(BinaryTree *bt) {
    if(bt == nullptr || *bt == nullptr)
        return 0;
    int height_left = nodeNumber(&((*bt)->left));
    int height_right = nodeNumber(&((*bt)->right));

    return (height_left + height_right + 1);
}

int tree_height(BinaryTree *bt) {
    if(bt == nullptr || *bt == nullptr)
        return 0;
    int height_left = tree_height(&((*bt)->left));
    int height_right = tree_height(&((*bt)->right));

    if(height_left > height_right)
        return (height_left + 1);
    else
        return (height_right + 1);
}

// Transversing tree: pre-order: root, left children, right children
void pre_order(BinaryTree *bt) {
    if(bt != nullptr && *bt != nullptr) {
        cout << (*bt)->number << " ";
        pre_order(&((*bt)->left));
        pre_order(&((*bt)->right));
    }
}

// Transversing tree: in-order: left, root, right
void in_order(BinaryTree *bt) {
    if(bt != nullptr && *bt != nullptr) {
        pre_order(&((*bt)->left));
        cout << (*bt)->number << " ";
        pre_order(&((*bt)->right));
    }
}

// Transversing tree: post-order: left, right, root
void post_order(BinaryTree *bt) {
    if(bt != nullptr && *bt != nullptr) {
        pre_order(&((*bt)->left));
        pre_order(&((*bt)->right));
        cout << (*bt)->number << " ";
    }
}

// Insertion in a Binary search tree
/*
    To insert a value in a binary search tree:
    first compare the value with the root,
    if v is lesser than the root
        go to the subtree at the left
    else
        go to subtree at the right

    apply the method recursively (but it can be done without recursion)
*/

int insert_value(BinaryTree *bt, int number) {
    if(bt == nullptr)
        return 0; // Error, the tree doesn't exist
    Node *no = (Node *)malloc(sizeof(Node));
    if(no == nullptr)
        return 0; // Error, when tried to allocate memory for the node
    no->number = number;
    no->left = no->right = nullptr;

    // Search where insert it
    if(*bt == nullptr) // If the tree is empty
        *bt = no; // First node of the tree
    else {
        Node *current = *bt;
        Node *previous = nullptr;
        while(current != nullptr) { // While the current value is different of null, that is, while it hasn't found an empty place to insert the value
            previous = current; // Previous receives the current value, since bellow current is going to change its value to either left or right node
            if(number == current->number) { // If the number passed already exist in the tree, then it will not be inserted, since the tree does not allow repeated numbers
                free(no);
                return 0; // Error, number already exist
            }

            if(number > current->number) { // If the number is greater than the number in the current node, then it must go to the right of it
                current = current->right;
            } else {
                current = current->left; // Otherwise, it goes to the left
            }
        }

        // When the current has achieved the null value, it has got into a empty place to insert the value then:
        //  previous stores the node previous to the current, previous is a leaf node
        if (previous->number < number) // The number must be inserted in the right
            previous->right = no;
        else
            previous->left = no;

        return 1; // Everything went okay
    }
}

Node* remove_current(Node *current) {
    Node *node1, *node2;

    // Without child at the left
    if(current->left == nullptr) {
        node2 = current->right;
        free(current);
        return node2;
    }

    node1 = current;
    node2 = current->left;

    // Search for a child at the rightmost side of the subtree at the left
    while(node2->right != nullptr) {
        node1 = node2;
        node2 = node2->right;
    }

    // Copy the rightmost child in the left subtree to the place of the removed node
    if(node1 != current) {
        node1->right = node2->left;
        node2->left = current->left;
    }

    node2->right = current->right;

    free(current);

    return node2;
}

// Delete a value in 3 situations: leaf node, one child and two children
int delete_value(BinaryTree *bt, int number) {
    if(bt == nullptr)
        return 0; // Error, binary tree doesn't exist

    Node *current = *bt;
    Node *previous = nullptr;

    while(current != nullptr) {
        if(number == current->number) {  // If the number was found, do the remotion of the value
            if(current == *bt) // If the number is at the root
                *bt = remove_current(current);
            else {
                if(previous->right == current) { // The node is at the right side
                    previous->right = remove_current(current);
                } else {
                    previous->left = remove_current(current); // The node is at the left side
                }

                return 1; // Finished
            }
        }

        // If the node wasn't found yet, keeping searching for value
        previous = current; // Previous receives the current one, since bellow it's going to change
        if(number > current->number) // If the number is greater than the number at the current node, then, it's supposed to be at the right
            current = current->right;
        else
            current = current->left; // Left
    }
}

