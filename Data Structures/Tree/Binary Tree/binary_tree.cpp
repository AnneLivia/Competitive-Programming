#include "binary_tree.h"
using namespace std;

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
        pre_order(&((*bt)->right)); // Right child
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

// Insert element
int inserting(BinaryTree *bt, int number) {
    if(bt == nullptr)
        return 0; // Error
    Vertex* v = (Vertex *)malloc(sizeof(Vertex));
    if(v == nullptr)
        return 0; // Error

    // Insert number passed and assert left and right to null
    v->number = number;
    v->left = v->right = nullptr;

    if(*bt == nullptr) {
        // If the tree does not have any value
        *bt = v; // BT will point to v, which is now the root
    } else {
        // Find an empty place
        queue <Vertex *> q;
        q.push(*bt); // Inserting the root in the queue
        // While an empty place is not found, the loop will run
        while(!q.empty()) {
            Vertex* temp = q.front(); // Getting the first element of the queue
            q.pop(); // At the beginning the queue has only the root element, and after this pop, this queue is empty
            if(!temp->left) { // If the temp->left is null, the node will be insert here
                temp->left = v; // Inserting the new node in the left
                break;
            } else {
                q.push(temp->left); // In case the left side is not empty, insert it in the queue, to in case the right is not empty too, it will search again
            }

            if(!temp->right) { // Same as above, but now with the right side
                temp->right = v;
                break;
            } else {
                q.push(temp->right);
            }
        }
    }

    return 1; // Everything went well
}

// Used to delete the deepest element
void delete_deepest(BinaryTree *bt, Vertex* v) {
    queue<Vertex *>q;
    q.push(*bt);

    // Find deepest node
    Vertex *temp;
    while(!q.empty()) {
        temp = q.front();
        q.pop();

        if(temp->right) { // if temp->right is different of null
            if(temp->right == v) { // if temp->right points to the same address as v
                temp->right = nullptr; // Setting temp->right to point to null, and then delete the vertex passed
                free(v);
                return; // Finish function
            } else {
                q.push(temp->right);
            }
        }

        if(temp->left) { // Same as above, but now with the left side
            if(temp->left == v) {
                temp->left = nullptr;
                free(v);
                return;
            } else {
                q.push(temp->left);
            }
        }
    }
}

// Deleting a specific element
void delete_node(BinaryTree *bt, int number) {

    if(bt != nullptr && *bt != nullptr) { // if the tree does exist and it's not empty
        // The idea is to find the deepest node and copy its value to the node that is going to be deleted and then, delete the deepest node
        queue<Vertex *> q;
        q.push(*bt);

        Vertex *temp, *previous = nullptr;
        Vertex *number_node = nullptr; // If the number does not exist in the tree, then it will null

        // find where the key node is and also the deepest node

        while(!q.empty()) {
            temp = q.front();
            q.pop();
            if(temp->number == number)
                number_node = temp;
            if(temp->left != nullptr) {
                previous = temp;
                q.push(temp->left);
            }
            if(temp->right != nullptr) {
                previous = temp;
                q.push(temp->right);
            }
        }

        if(number_node != nullptr) { // If the number was found
            if(temp == number_node) { // If the number to be deleted is the deepest node
                if(previous == nullptr) { // There's only one element
                    *bt = nullptr; // Root is now pointing to null
                    free(temp); // free temp.
                } else {
                    if(previous->right == temp) // checking if is the right side
                        previous->right = nullptr; // Previous->right points to the deepest node
                    if(previous->left == temp) // checking if is the left side
                        previous->left = nullptr;
                    free(temp); // Free temp node
                }
            } else {
                int x = temp->number; // Copying the number of the deepest node
                delete_deepest(bt,temp); // Delete deepest element
                number_node->number = x; // Inserting the number of the deepest node in the node that is going to be deleted
            }
        }
    }
}
