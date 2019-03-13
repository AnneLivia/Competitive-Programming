#include <iostream>
#include <cmath>

using namespace std;

/*
    An AVL Tree is a self-balancing binary search tree (BST) where the
    difference between heights of left and right subtrees cannot be more than
    one for all nodes.
    In Computer science a self-balancing or height-balanced binary search tree is any
    node-based BST that automatically keeps its height (maximum number of levels bellow the root)
    small in face of insertions and deletions.
    The height is typically maintained in order of Log n so that all operations take O(Log n) time on average.
    Examples of self-balancing tree:
        Red black tree
        AVL tree
        2-3-4 Tree
    AVL stands for: Adelson-Velsky and Landis, its creators.
    That was the first data structure to be invented, in 1962.
    AVL trees are faster than red black trees because they are more strictly balanced.

    The height difference is called balance factor
    In a binary search tree, the efficiency of a search is depended on the balancing.
    Problem:
        Insertion and deletion doesn't guarantee that a tree is balanced.
        Example:
            1
             \
              2
               \
                3
                 \
                 10
                /
               4
               \
                5
                \
                9
        ...........
        Balanced: O(log n)
        not-balanced: O(n)
        N is the number of nodes
        It's important to keep a BST balanced, and the solution is to use self-balanced tree:
            What is the solution for the balancing problem ?
                modify the operations of insertion and deletion
        .....

    For the AVL tree, only the part affected by the insertion or deletion is going to be rebalanced
    it uses simple or double rotations in the rebalanced stage.

    It's try to be a Binary Tree almost complete.
    we use the balance factor, which store 0, 1 or -1, where:
        0: height is the same for both sides of its subtrees, left and right
        1: height is one node greater to the left compared with the right
       -1: height is one node greater to the right compared with the left
    the balanced factor is determined by the difference of the left and height subtree
    if one of the subtree does not exist, the height is going to be -1
        BF = LH - RH; balance factor = left height - right height
        if the number is greater than 1 here or less than 1, it must be balanced
    to turn a not balanced tree to a balanced tree, we apply a operation of rotation
    the implementation of a AVL tree is almost the same as the BST.
*/

struct Node {
    int number, height;
    Node *leftChild, *rightChild;
};

class AVLtree {
private:
    // it's a pointer by pointer, so that is most easier to store the address of a pointer,
    // in that way, it's easier to change the root if necessary.
    Node **root;

    // Private methods to perform some operations
    int numberOfNodesUTIL(Node *no) {
        if(no == nullptr)
            return 0;
        int nodesLeft = numberOfNodesUTIL(no->leftChild);
        int nodesRight = numberOfNodesUTIL(no->rightChild);

        // return combination of nodes left + nodes right + 1 new node.
        return nodesLeft + nodesRight + 1;
    }

    int heightUTIL(Node *no) {
        if(no != nullptr) {
            int heightLeft = heightUTIL(no->leftChild);
            int heightRight = heightUTIL(no->rightChild);

            if(heightLeft > heightRight) {
                return heightLeft + 1;
            } else {
                return heightRight + 1;
            }
        } else {
            return 0;
        }
    }

    bool insertNodeUtil(int value, Node **node) {
        // check if node is null, in case it's null, insert the value there
        int res = false;
        if(*node == nullptr) {
            // allocate memory (value, height, leftChild, rightChild)
            *node = new Node({value, 0, nullptr, nullptr});
            return true; // it was found an empty node to insert the value
        } else {
            // going through each node recursively
            // if value is smaller than the current node, go to left
            if(value < (*node)->number) {
                // the function returns a boolean, then if a node was inserted when return back to this function, it will return true
                if(res = insertNodeUtil(value, &(*node)->leftChild)) {
                    // re-balance tree if necessary, that is, if balance factor of node is greater than 2
                    if(balanceFactor(*node) >= 2) {
                        // since we are inserting a value in the left, check if it's necessary a double or simple rotation
                        if(value < (*node)->leftChild->number) {
                            // if this is true, it means that the node was inserted in the left subtree of the left subtree of the root
                            // then apply simple right rotation (LL rotation)
                            LLrotation(node);
                        } else {
                            // then the node was inserted in the left subTree, but on the right
                            LRRotation(node);
                        }
                    }
                }
            } else if (value > (*node)->number) {
                // if value is greater than the current node, go to right
                // the function returns a boolean, then if a node was inserted when return back to this function, it will return true
                if(res = insertNodeUtil(value, &(*node)->rightChild)) {
                    // re-balance tree if necessary, that is, if balance factor of node is greater than 2
                    if(balanceFactor(*node) >= 2) {
                        // since we are inserting a value in the left, check if it's necessary a double or simple rotation
                        if(value > (*node)->rightChild->number) {
                            // if this is true, it means that the node was inserted in the right subtree of the right subtree of the root
                            // then apply simple left rotation (RR rotation)
                            RRrotation(node);
                        } else {
                            // then the node was inserted in the right subTree, but on the left
                            RLRotation(node);
                        }
                    }
                }
            } else {
            // if value is neither greater nor smaller, this is equal to some other node on the tree,
            // which means that the value was duplicated
                return false; // so return false, value was not added
            }
        }
        // it will get here, and will update each height of each node, when return to function calls
        (*node)->height = greaterValue(height_node((*node)->leftChild), height_node((*node)->rightChild)) + 1; // plus this current added node
        return res; // return true or false.
    }
    // this function is responsible for treat the remotion of a node with two children
    Node* find_minimum_node(Node* node) {
        Node *node1 = node;
        Node *node2 = node->leftChild;
        // search for the most left child which is guarantee to be the minimum one
        while(node2 != nullptr) {
            node1 = node2; // current node receives the left node
            node2 = node2->leftChild;
        }
        return node1;
    }

    bool removeNodeUtil(int value, Node **root) {
        // three types of remotion:
        // - if node is a leaf (no child)
        // - if node has 1 child
        // - if node has 2 child
        // for balance, remove a node from left, is the same as insert a node in the right
        // we remove a node from one side and re-balance the tree on the other side
        // base case
        if(*root == nullptr) {
            // value doesn't exist
            return false;
        }
        // variable to store result and and the end return in case of success or failure
        bool res = false;
        // if value is smaller, the value is on the left subtree of the current node.
        if(value < (*root)->number) {
            // checking the return of the function called recursively
            if((res = removeNodeUtil(value, &(*root)->leftChild))) {
                // if this condition is satisfied, it means the node was found
                // checking balance factor, since the node to be remove is on the left,
                // that's the same as add a node on the right, so, we need to use either the
                // rotation RR or RL, in case the balance factor of a node is greater or equal than 2.
                if(balanceFactor(*root) >= 2) {
                    // in case the height of the left child of the right child of root is smaller or equal to the
                    // right child of the right child of the root, then:
                    // it means that the rotation function that must be used is the RR (when a node is added on the right subtree,
                    // of the right subtree), since the height of the right child of the right child is largest.
                    if(height_node((*root)->rightChild->leftChild) <= height_node((*root)->rightChild->rightChild)) {
                        RRrotation(root);
                    } else {
                        // otherwise, the node was added on the right subtree but on the left subtree
                        LRRotation(root);
                    }
                }
            }
        } else if (value > (*root)->number) {
            // in case the value is greater than the current node, it was added on the right
            if(res = removeNodeUtil(value, &(*root)->rightChild)) {
                // in case it gets here, value was found
                // checking balance factor, if it's greater than two or not
                if(balanceFactor(*root) >= 2) {
                    // if it gets here, it's necessary to re-balance the tree
                    // since the removed node is on the right, then it's is as a node was added on the
                    // left side of the tree, so it can be used either LLrotation in case the height of the
                    // left child of the left child is greater or LRrotation in case the height of the right child
                    // of the left child is greater.
                    if(height_node((*root)->leftChild->leftChild) >= height_node((*root)->leftChild->rightChild)) {
                        LLrotation(root);
                    } else {
                        // it was added on the left subtree of root and on the right subtree of left subtree;
                        LRRotation(root);
                    }
                }
            }
        } else {
            // otherwise the value is equal to the value on the current node
            // checking if it's a leaf node (without children) or has only one child
            if((*root)->leftChild == nullptr || (*root)->rightChild == nullptr) {
                Node *rNode = *root;
                // updating the root with one new root or null
                if((*root)->leftChild != nullptr) {
                    // it value is different of null, get the node on the left
                    *root = (*root)->leftChild;
                } else {
                    // otherwise, get either node on the right in case it exists or get null
                    *root = (*root)->rightChild;
                }
                // remove node
                delete rNode;
            } else {
                // in case node has two children
                // get minimum element
                Node *nm = find_minimum_node((*root)->rightChild);
                // updating root info with the minimum value found with the above function
                (*root)->number = nm->number;
                // removing node now
                removeNodeUtil((*root)->number, &(*root)->rightChild);
                // balance
                if(balanceFactor(*root) >= 2) {
                    if(height_node((*root)->leftChild->rightChild) <= height_node((*root)->leftChild->leftChild)) {
                        LLrotation(root);
                    } else {
                        LRRotation(root);
                    }
                }
                return true;
            }
        }

        return res;
    }

    void pre_orderUTIL(Node *no) {
        if(no != nullptr) {
            cout << no->number << endl;
            pre_orderUTIL(no->leftChild);
            pre_orderUTIL(no->rightChild);
        }
    }

    void in_orderUTIL(Node *no) {
        if(no != nullptr) {
            in_orderUTIL(no->leftChild);
            cout << no->number << endl;
            in_orderUTIL(no->rightChild);
        }
    }

    void post_orderUTIL(Node *no) {
        if(no != nullptr) {
            post_orderUTIL(no->leftChild);
            post_orderUTIL(no->rightChild);
            cout << no->number << endl;
        }
    }

    // some auxiliary functions
    // return the height of a node
    int height_node(Node *node) {
        // if that node doesn't exist
        if(node == nullptr)
            return -1;
        // otherwise, return its height
        return node->height;
    }

    // calculate the balance factor of a node
    int balanceFactor(Node *node) {
        // the difference of heights
        // the sign of a number - or +, just tell what rotation we must choose
        return abs(this->height_node(node->leftChild) - this->height_node(node->rightChild));
    }

    // checking greater value
    int greaterValue(int value1, int value2) {
        return value1 > value2 ? value1 : value2;
    }

public:
    AVLtree() {
        root = new Node*();
    }

    bool isEmpty() {
        return (root == nullptr || *(this->root) == nullptr);
    }

    bool searchElement(int value) {
        Node *nodeAux = *(this->root);

        while(nodeAux != nullptr) {
            // if element was found
            if(nodeAux->number == value) {
                return true;
            }
            // go to right
            if(value > nodeAux->number) {
                nodeAux = nodeAux->rightChild;
            } else {
                // go to left
                nodeAux = nodeAux->leftChild;
            }
        }
        return false;
    }

    void remove_nodes(Node *node) {
        // if node is different of null it can be removed
        if(node != nullptr) {
            // using post-order transversing
            remove_nodes(node->leftChild);
            remove_nodes(node->rightChild);
            // when it gets here, it means that there's any other node to check
            delete node;
            // avoid dangling pointer
            node = nullptr;
        }
    }

    /* rotation functions:
        simple: The node is unbalanced and its child are in the same (tilt) inclination direction
        double: the node is unbalanced and its child are tilt in the inverse direction to the parent node.
        it's equivalent to two simple rotations.

        There are 2 simple rotation and 2 double rotation
            - one to the left, and another to the right

        The Rotations are performed in the following ways:
            - Simple left Rotation or RR (Right Right) rotation:
                For the following tree:
                        A   balance factor (-2)
                         \
                          B balance factor (-1)
                           \
                            C balance factor (0)
            The C node was added in the tree, in the right subtree of the right subtree of A.
            The intermediate node B, is choose to be the root in this case.
                Using the RR rotation, it would become:
                        B  balance factor (0)
                      /  \
 balance factor (0)  A    C balance factor (0)

            Simple right Rotation or LL (Left Left) rotation:
                For the following tree:
                        A balance factor (+2)
                       /
                      B balance factor (+1)
                     /
                    C balance factor (0)
                Using the RR rotation, it would become:
                        B  balance factor (0)
                      /  \
 balance factor (0)  C   A balance factor (0)
            The C node was added in the tree, in the left subtree of the left subtree of A.
            The intermediate node B, is choose to be the root in this case.

        Double left rotation - RL (right left) rotation
            For the following tree:
                        A balance factor (-2)
                         \
                          B balance factor (+1)
                        /
                       C balance factor (0)
            LL rotation:
                        A balance factor (-2)
                         \
                          C balance factor (-1)
                           \
                            B balance factor (0)
            RR rotation:
                          C balance factor (0)
                        /   \
                       A    B balance factor (0)
        The C node was added in the tree, in the left subtree of the right subtree of A.
        The node C, is choose to be the root in this case.

        Double Right rotation - LR (Left Right) rotation
            For the following tree:
                        A balance factor (+2)
                       /
                      B balance factor (-1)
                      \
                       C balance factor (0)
            RR rotation:
                        A balance factor (+2)
                       /
                      C balance factor (+1)
                     /
                    B balance factor (0)
            LL rotation:
                          C balance factor (0)
                        /   \
                       B     A balance factor (0)
        The C node was added in the tree, in the right subtree of the left subtree of A.
        The node C, is choose to be the root in this case.

        When to use each rotation:
            Considering that node C was added, and node C is child of node B which is child of node A,
            if the balance factor is:
                A == +2 && B == +1: Rotation LL
                A == -2 && B == -1: Rotation RR
                A == +2 && B == -1: Rotation LR
                A == -2 && B == +1: Rotation RL
        The rotations LL and RR are symmetric, so are LR and RL.

        The rotations are applied to the ancestor closer to the inserted node in which balance factor turn out to be
        +2 or -2.
        The simple rotations update the heights of the subtrees
        The double rotations can be implemented using the simple rotations

    */
    // Simple Right rotations (The node was inserted in the left subtree of the left subtree)
    void LLrotation(Node **rt) {
        /*
               A                       B
              / \                     / \
             B   C  LL rotation      D   A
            / \                     /   / \
           D   E                   F   E   C
          /
         F
        */
        // Auxiliary node receive left child of root, since it will be overwritten.
        Node *node = (*rt)->leftChild;
        // left child of root is now going to point to the right child of its left child
        (*rt)->leftChild = node->rightChild;
        // right child of node is now going to be the root.
        node->rightChild = *rt;
        // updating height of root
        (*rt)->height = greaterValue(height_node((*rt)->leftChild), height_node((*rt)->rightChild)) + 1;
        // updating height of node
        node->height = greaterValue(height_node(node->leftChild), (*rt)->height) + 1;
        // updating root which is now the root that was the left child of the previous root.
        *rt = node;
    }

    // Simple Left rotations (The node was inserted in the right subtree of the right subtree)
    void RRrotation(Node **rt) {
        /*
               A                          C
              / \                        / \
             B   C     RR rotation      A   E
                / \                    / \   \
               D   E                  B   D   F
                    \
                     F
        */
        // Auxiliary node receive right child of root, since it will be overwritten.
        Node *node = (*rt)->rightChild;
        // right child of root is now going to point to the left child of its right child
        (*rt)->rightChild = node->leftChild;
        // right child of node is now going to be the root.
        node->leftChild = *rt;
        // updating height of root
        (*rt)->height = greaterValue(height_node((*rt)->leftChild), height_node((*rt)->rightChild)) + 1;
        // updating height of node
        node->height = greaterValue(height_node(node->rightChild), (*rt)->height) + 1;
        // updating root which is now the root that was the right child of the previous root.
        *rt = node;
    }

    // When a node is insert on the left-subtree of the right subtree
    void LRRotation(Node **rt) {
        // Rotation to the right first
        RRrotation(&(*rt)->leftChild);
        // rotation to the left secondly
        LLrotation(rt);
    }

    // When a node is insert on the right-subtree of the left subtree
    void RLRotation(Node **rt) {
        // Rotation to the right first
        LLrotation(&((*rt)->rightChild));
        // rotation to the left secondly
        RRrotation(rt);
    }

    // insert a node in the tree
    bool insertNode(int value) {
        /*
            To insert a value to a Node:
                If root is null: insert the node there.
                If v is smaller than the root:
                    go to left
                if v is greater than the root:
                    go to right
                this is applied recursively
            when return from recursion, recalculate the height of each subtree
            apply rotation if it's necessary to re-balance the tree, in case the
            BF (balance factor) is -2 or +2.
        */
		if (*root == nullptr) {
			Node *no = new Node({ value, 0, nullptr, nullptr });
			*root = no;
			return true;
		} else {
			return insertNodeUtil(value, root);
		}
    }

    // remove a node from the tree
    void removeNode(int value) {
        removeNodeUtil(value, root);
    }

    // calculating number of nodes
    int numberOfNodes() {
        return numberOfNodesUTIL(*(this->root));
    }
    // calculating height of a tree
    int height() {
        return heightUTIL(*(this->root));
    }

    // pre order: number, node left and node right
    void pre_order() {
        pre_orderUTIL(*(this->root));
    }

    // in order: node left, number, and node right
    void in_order() {
        in_orderUTIL(*(this->root));
    }

    // post order: node left, node right and number
    void post_order() {
        post_orderUTIL(*(this->root));
    }

    ~AVLtree() {
        remove_nodes(*(this->root));
        delete root;
        root = nullptr;
    }
};

int main()
{
    AVLtree avl;
    avl.insertNode(2);
    avl.insertNode(1);
    avl.insertNode(3);
    avl.insertNode(10);
    avl.insertNode(4);
    avl.insertNode(9);
    avl.insertNode(7);
    avl.insertNode(5);
    avl.insertNode(8);
    avl.insertNode(6);

    int n;
    while(!avl.isEmpty()) {
        avl.pre_order();
        cout << "Remove node: ";
        cin >> n;
        avl.removeNode(n);
        system("cls");
    }

    cout << "AVL Tree is empty\n";
    return 0;
}
