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
        in_order(&((*bt)->left));
        cout << (*bt)->number << " ";
        in_order(&((*bt)->right));
    }
}

// Transversing tree: post-order: left, right, root
void post_order(BinaryTree *bt) {
    if(bt != nullptr && *bt != nullptr) {
        post_order(&((*bt)->left));
        post_order(&((*bt)->right));
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
    }
    return 1; // Everything went okay
}

// That function is responsible to treat all possible configurations of deletion
// when the node has no child, only one child and two children
Node* remove_current(Node *current) {
    Node *nodeLeft, *nodeRight;

    // without any child
    if(current->left == nullptr && current->right == nullptr) {
        // deallocating memory
        free(current);
        // avoid dangling pointer
        current = nullptr;
        // return null to the previous node that was pointing to the removed node
        return nullptr;
    }

    // Without a child at the left but with one at the right
    if(current->left == nullptr) {
        // making the previous node pointing to whatever child the current node was pointing to
        // since it has only one child, and in this case at the right.
        nodeRight = current->right;
        // deallocating memory
        free(current);
        // avoid dangling pointer
        current = nullptr;
        // return the right child to the previous one
        return nodeRight;
    }

    // in case there's only one child, but now at the left
    if(current->right == nullptr) {
        // making the previous node pointing to whatever child the current node was pointing to
        // since it has only one child, and in this case at the left.
        nodeLeft = current->left;
        // deallocating memory
        free(current);
        // avoid dangling pointer
        current = nullptr;
        // return the left child to the previous one
        return nodeLeft;
    }

    // If it has gotten here, it means that the node to be deleted has two children
    // so now it's time to search for a child at the rightmost side of the left subtree
    // to overwrite the node to be deleted. that guarantees that the node taken from the
    // rightmost side is lesser then the right child of the current node and this node is greater than the
    // left child of the current node.

    Node* previous = current;
    // left subtree
    nodeRight = current->left;

    // Search for a child at the rightmost side of the subtree at the left
    // while the nodeLeft is different of null, we haven't got to the rightmost child yet
    while(nodeRight->right != nullptr) {
        previous = nodeRight;
        // moving to the right child
        nodeRight = nodeRight->right;
    }
    // when node nodeRight->right is null, it means the rightMost child was found
    // So now we can use the previous node that points to the right most child to point
    // to whatever the right most child was pointing to, in case it has a left child
    // and make the rightNode pointing to as its left child to the left child of the current node.
    // Replace the removed node with the rightmost child in the left subtree
    if(previous != current) {
        // if it get here, it means that it was found a rightmost node, otherwise, the
        // left child of current hasn't any right most child, which means that it must
        // be swapped with the current node. (that's going to be the node that is going to pointing
        // to whatever current was pointing to. i.e. it will be pointing to the right child of the removed node.

        // in case the rightmost child has a left child
        previous->right = nodeRight->left;
        // making the rightmost child point to the left child of current
        nodeRight->left = current->left;
    }

    // node right points to the right child of current one
    nodeRight->right = current->right;

    free(current);
    // avoiding dangling pointer
    current = nullptr;
    // returning rightmost child for the previous node from the removed one point to it
    return nodeRight;
}

/*
    When the node has no child, we can simply make its parent node (previous) point to null
    When the node has only one child (either left or right), make the previous node to it point to the child it was pointing
    When the node has two children, to guarantee that after the deletion of a node, the binary search tree keep following the rules of a BST
    we need to take the a child from the left subtree that is a most-right node and replace where the node is going to be deleted.
    so that it's guarantee that this node is greater than the left child and smaller than the right child.
*/
// Delete a value in 3 situations: leaf node, one child and two children
int delete_value(BinaryTree *bt, int number) {
    if(bt == nullptr)
        return 0; // Error, binary tree doesn't exist

    // Pointers to keep track of the previous one to the node
    Node *current = *bt;
    Node *previous = nullptr;

    while(current != nullptr) {
        // If the number was found, do the remotion of the value
        if(number == current->number) {
            // If the number is the root (check if root has one, two or none child)
            if(current == *bt) {
                *bt = remove_current(current);
            } else {
                // otherwise, if it's not the root, then
                // checking if the element is at the right or left
                // The node is at the right side
                if(previous->right == current) {
                    // so the right node that previous was pointing to must be updated to either null, the only child the
                    // node to be deleted was pointing to, or the right-most child from the left subtree
                    previous->right = remove_current(current);
                } else {
                    // If it's not the right, do the same for the left
                    // The node is at the left side
                    previous->left = remove_current(current);
                }
            }
            // return 1, to specify that the element was removed
            return 1;
        }

        // If the node wasn't found yet, keeping searching for value
        previous = current; // Previous receives the current one, since bellow it's going to change
        if(number > current->number) // If the number is greater than the number at the current node, then, it's supposed to be at the right
            current = current->right;
        else
            current = current->left; // Otherwise, it's at the left subtree
    }

    return 0;
}

bool searchElementUtil(Node *node, int v) {
    // if node is equal to null it means that the value wasn't found
    if(node == nullptr)
        return false;
    // otherwise, check if number is equal to the current node
    if(node->number == v) {
        // return true in this case
        return true;
    } else {
        // otherwise, check if the number might be in the right side or left
        if(v < node->number) {
            // might be at the left since its smaller than the number at the current node
            return searchElementUtil(node->left, v);
        } else {
            // otherwise, it might be at the right
            return searchElementUtil(node->right, v);
        }
    }
}

bool searchElement(BinaryTree* bt, int v) {
    // if binary doesn't exists or is empty
    if(bt == nullptr || *bt == nullptr)
        return false;
    // otherwise search for an element, it can be either recursive or not
   return searchElementUtil(*bt, v);
}

