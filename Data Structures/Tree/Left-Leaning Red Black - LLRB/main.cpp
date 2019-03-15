#include <iostream>
#include <cmath>

using namespace std;

/*
    Invented by Rudolf Bayer.
    A Red black tree is a self-balancing tree that uses a color (red or black)
    do determine if the tree, after insertion and deletion, remain balanced.
    Balanced tree guarantees to have of height where the complexity is O(log n) for n nodes.
    One unbalanced tree code be:
            8 That uses a simple binary search tree, and all added nodes are smaller than its root
           /  that causes it to be unbalanced, let's supposed we would like to search for a number
          2   and that number doesn't exist on the tree, we would have to run through all n nodes.
         /
        1
       /
      0
    Complexity:
        space O(n)
        search O(log n)
        insert O(log n)
        delete O(log n)
    Informations:
        - A node can be of color red or black.
        - the root is black.
        - if a node is red, its children are black (there are no two adjacent red nodes).
        - all paths from a node to its descendants null has the same number of black nodes.

    AVL Tree x Red Black trees:
        AVL Tree are more balanced than red black tree, but they cause more rotations more insertion
        and deletions.
        If insertion and deletion is more frequent
            AVL is preferred
        If search is done more frequent than search
            Red Black tree is preferred
    To re-balance a tree are used rotations and colors adjustment
    A red black tree tries to be like a binary search tree almost complete

    red black tree are more used than AVL:
        C++ STL: map, multimap and multiset.
        Java: TreeMap and TreeSet.

    A left-leaning red black (LLRB) tree is a variant of the red black tree and guarantees
    the same complexity for operations, but is designed to be easier to implement.
    It has one extra properties, if one node is red, then it is the left child of its parent.
    Left-Leaning here is used because of it, all red nodes are left child.
    it's implementation is done using a 2-3 tree (not binary tree)
    in a 2-3 tree, each node can store one or two value and, depending upon the amount of values, it can has
    one child (one value) or tree child (two values).
    In a case a 3 sub-trees: in the middle there are the elements greater than the first but smaller than the second value of
    the parent.
    the red node here could be the smaller number in a node containing 2 or 3 children.
*/

// colors for the red black tree
#define BLACK 0
#define RED 1

struct Node {
    int data, color;
    Node *left, *right;
};

class RedBlackTree {
private:
    Node **root;

    void deleteAllNodes(Node *no) {
        if(no != nullptr) {
            deleteAllNodes(no->left);
            deleteAllNodes(no->right);
            delete no;
            no = nullptr;
        }
    }

    void pre_orderUtil(Node *no) {
        if(no != nullptr) {
            cout << no->data << "\n";
            pre_orderUtil(no->left);
            pre_orderUtil(no->right);
        }
    }

    int numberOfNodesUtil(Node *no) {
        // base
        if (no == nullptr)
            return 0;
        // recursive case
        int nLeft = numberOfNodesUtil(no->left);
        int nRight = numberOfNodesUtil(no->right);

        return nLeft + nRight + 1;
    }

    bool insertNodeUtil(int value, Node **root) {
        bool result = false;
        /*
            To insert a value "V" in the tree:
                - root is null: insert the node
                - v is smaller than the root:
                    go to left subtree
                - v is greater than root:
                    go to right subtree
                apply this method recursively
            = when recursion calls return, verify each properties of each subtree
            = apply rotation or change color if any property was violated
        */

        // base case
        if(*root == nullptr) {
            // it was found an empty place to insert the value
            // allocate memory
            Node *no = new Node({value, RED, nullptr, nullptr});
            *root = no;
            // return true to specify that the node was inserted
            return true;
        }

        if(value == (*root)->data) {
            return false;
            // if value equals to the node, return false, because it cannot have repeated values
        } else if (value < (*root)->data) {
            // value is smaller than the data
            // go to left subtree, this function is going to return true if node is inserted on the tree, and false otherwise
            if(result = insertNodeUtil(value, &(*root)->left)) {
                // check if tree hasn't violated the properties
                // red node must be on the left
                if(color((*root)->right) == RED && color((*root)->left) == BLACK) {
                    *root = leftRotation(*root);
                }
                // consecutive red nodes
                if(color((*root)->left) == RED && color((*root)->left->left) == RED) {
                    *root = rightRotation(*root);
                }
                // left and right are red
                if(color((*root)->left) == RED && color((*root)->right) == RED) {
                    changeColor(*root);
                }
            }
        } else {
            // value is greater than the data
            // go to right subtree, this function is going to return true if node is inserted on the tree, and false otherwise
            if(result = insertNodeUtil(value, &(*root)->right)) {
                // check if tree hasn't violated the properties
                // check if tree hasn't violated the properties
                // red node must be on the left
                if(color((*root)->right) == RED && color((*root)->left) == BLACK) {
                    *root = leftRotation(*root);
                }
                // consecutive red nodes
                if(color((*root)->left) == RED && color((*root)->left->left) == RED) {
                    *root = rightRotation(*root);
                }
                // left and right are red
                if(color((*root)->left) == RED && color((*root)->right) == RED) {
                    changeColor(*root);
                }
            }
        }

        return result;
    }

    /*
        Three types of remotion:
            leaf node
            node with one child
            node with two child
        when recursion calls returns, verify the properties of each subtree
        apply the rotation or change color if any property is violated

    */

    Node* remove_node(Node *no, int value) {
        if(value < no->data) {
            if(color(no->left) == BLACK && color(no->left->left) == BLACK)
                no = moveToTheLeft(no);
            no->left = remove_node(no->left, value);
        } else {
            if(color(no->left) == RED) {
                no = rightRotation(no);
            }
            if(value == no->data && (no->right == nullptr)) {
                delete no;
                return nullptr;
            }
            if(color(no->right) == BLACK && color(no->right->left) == BLACK) {
                no = moveToTheRight(no);
            }
            if(value == no->data) {
                Node* temp = search_smaller(no->right);
                no->data = temp->data;
                no->right = remove_smaller(no->right);
            } else {
                no->right = remove_node(no->right, value);
            }
        }
        return balance(no);
    }

    Node* remove_smaller(Node* no) {
        if(no->left == nullptr) {
            delete no;
            no = nullptr;
            return nullptr;
        }

        if(color(no->left) == BLACK && color(no->left->left) == BLACK) {
            no = moveToTheLeft(no);
        }
        no->left = remove_smaller(no->left);
        return balance(no);
    }

    Node* search_smaller(Node* no) {
        Node *previous = no;
        Node *current = no->left;
        // getting the most left child of the left subtree, so that we can get the minimum node
        while(current != nullptr) {
            previous = current;
            current = current->left;
        }
        return previous;
    }

    bool deleteNodeUtil(int value, Node **root) {
        // base case, search value
        if(search_node(value)) {
            // if found value, remove it
            Node* no = *root;
            *root = remove_node(no, value);
            // if root is null, assign the color to it as black (all null are black)
            if(*root != nullptr)
                (*root)->color = BLACK;
            return true; // element was removed
        } else {
            // element wasn't found
            return false;
        }
    }

    // access color of a node
    int color(Node *no) {
        if(no == nullptr)
            return BLACK; // if it doesn't exist, return black, null is always black
        return no->color;
    }

    // invert color of parent node and its children
    // it doesn't change the structure of the tree
    void changeColor(Node *no) {
        no->color = !no->color; // if 1, get 0, and vice versa
        if(no->left != nullptr)
            no->left->color = !no->left->color;
        if(no->right != nullptr)
            no->right->color = !no->right->color;
    }

    /*  two types of rotations on the LLRBtree, left and right.
        given a set of 3 nodes, the rotation aims to dislocate one red node
        to the right and vice versa.
        The rotation takes O(1) because it utilizes only pointer
    */

    Node* leftRotation (Node *no){
        /* left rotation takes a node A with B as its right child.
           mode B to the place of A, and A becomes the left child of B.
           B receives color of A, and A becomes RED.
           root                           root
            |        Left Rotation         |
            A            <<->>             B
           / \                            / \
        Null  B                          A  Null
                and swap colors
            if:
                A (black) ->> A(red)
                B (red)   ->> B(black)
            and vice versa

        */
        // temp (B) receives A
        Node *temp = no->right;
        // no (A) points to whatever B (temp) was point to the left
        no->right = temp->left;
        // node: right child of B hasn't been disappeared
        // temp (B) change its left child to A now
        temp->left = no;
        // swap colors
        temp->color = no->color;
        no->color = RED; // no is now red
        return temp;
    }

    Node* rightRotation (Node *no){
        /* right rotation takes a node A with B as its left child.
           mode B to the place of A, and A becomes the right child of B.
           B receives color of A, and A becomes BLACK.
           root                           root
            |        Right Rotation        |
            A            <<->>             B
           / \                            / \
          B  null                      null  A
                and swap colors
            if:
                A (black) ->> A(red)
                B (red)   ->> B(black)
            and vice versa

        */
        // temp (B) receives A
        Node *temp = no->left;
        // no (A) points to whatever B (temp) was point to the right
        no->left = temp->right;
        // node: left child of B hasn't been disappeared
        // temp (B) change its left child to A now
        temp->right = no;
        // swap colors
        temp->color = no->color;
        no->color = RED; // no is now red
        return temp;
    }

    /*
        Moving red nodes:
            there must have 3 functions to establish the balancing of the tree
            and its properties are respected
                - move a red node to the left
                - move a red node to the right
                - fix balancing
            - this functions move red node to the left subtree or right, depending upon their places.
    */

    // move a red node to the left
    Node* moveToTheLeft(Node *no) {

        /*
            suppose we have this:
                A (red)
              /  \
            null  C (black)
                 /
                B (red)
            change color of root A and its children, becomes:
                A (black)
              /  \
            null  C (red)
                 /
                B (red)
            1 property is violated here: consecutive red nodes
            rotate the right child to the right
                A (black)
              /  \
            null  B (red)
                   \
                    C (red)
            rotate the node to the left
                B (black)
              /  \
       (red) A   C (red)
            change color
                B (red)
              /  \
     (black) A   C (black)

        */

        // Change color of it and its children
        changeColor(no);
        // if the left child of the right child is red,
        if(color(no->right->left) == RED) {
            // apply one right rotation to the right child
            no->right = rightRotation(no->right);
            // apply one left rotation to the left child
            no = leftRotation(no);
            // change color of it and its children.
            changeColor(no);
        }

        return no;
    }

    // move a red node to the right
    Node* moveToTheRight(Node *no) {
        /*
            C (red)
           /
          B (black)
         /
        A (red)

        change colors of C and B
            C (black)
           /
          B (red)
         /
        A (red)
        one property is violated here (2 subsequent reds)
        rotation to the right
                  B (black)
                /   \
            A (red)  C (red)
        change color
                B (red)
                /   \
            A (black)  C (black)
        */
        // Change color of it and its children
        changeColor(no);
        // if the left child of the left child is red,
        if(color(no->left->left) == RED) {
            // apply one right rotation to the node
            no = rightRotation(no);
            // change color of it and its children.
            changeColor(no);
        }

        return no;
    }

    // fix balance
    // if right child is red: rotation left
    // if right child and grandchild of left are red: rotation right
    // if both child are red: change color of father and children
    Node *balance(Node *no) {

        // red node is always on the left, fix this by rotating to the left
        if(color(no->right) == RED)
            leftRotation(no);
        // when right child and left left child is red, rotate to the right to fix this
        if(no->left != nullptr && color(no->right) == RED && color(no->left->left) == RED)
            rightRotation(no);
        // two red children, change color
        if(color(no->left) == RED && color(no->right) == RED)
            changeColor(no);
        return no;
    }
public:
    RedBlackTree() {
        root = new Node*();
    }

    bool insertNode(int value) {
        if(*root == nullptr) {
            *root = new Node({value,BLACK,nullptr,nullptr});
            return true;
        }
        return insertNodeUtil(value, root);
    }

    bool search_node(int value) {
        Node *no = *(root);

        while(no != nullptr) {
            if(no->data == value)
                return true;
            if(value < no->data)
                no = no->left;
            else
                no = no->right;
        }

        return false;
    }

    void deleteNode(int value) {
        deleteNodeUtil(value, root);
    }

    void pre_order() {
        pre_orderUtil(*root);
    }

    int numberOfNodes() {
        return numberOfNodesUtil(*root);
    }

    bool isEmpty() {
        return (root == nullptr || *root == nullptr);
    }

    ~RedBlackTree() {
        deleteAllNodes(*root);
        delete root;
        root = nullptr;
    }
};

int main()
{
    RedBlackTree tree;
    int number;
    while(1) {
        tree.pre_order();
        cout << "Type a number (negative to quit): ";
        cin >> number;
        if(number < 0)
            break;
        tree.insertNode(number);
        system("cls");

    }

    system("cls");

    number = 0;
    while(!tree.isEmpty() && number >= 0) {
        tree.pre_order();
        cout << "Remove a node (negative to quit): ";
        cin >> number;
        if(number < 0)
            break;
        tree.deleteNode(number);
        system("cls");
    }

    return 0;
}
