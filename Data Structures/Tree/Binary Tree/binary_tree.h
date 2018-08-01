#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <cstdlib>
#include <iostream>
#include <queue>

/*
    What is a tree?
    Tree are a special type of graph where each
    pair of vertex is connected with only one edge
    It's a connected graph ( In a connected graph, it is possible
    to get from every vertex in a graph to every other vertex in the graph through
    a series of edges, called a path.) and the tree is a acyclic graph.

    Properties:
    Root: immediately predecessor of a vertex
    child: immediately successor of a vertex
    root doesn't have a "parent".
    the nodes in the end of the trees are called leaves: any vertex that doesn't have a child
    intern nodes: any vertex that pursue at least one child

    Paths in a tree: it's a sequence of vertex in a way that always exist a vertex connecting the predecessor with the next one
    There is exactly a path in between the root and each node of the tree

    Sub-tree: given a specific vertex, each "child" is the root of a new sub-tree

    Vertex degree: it's the number of sub-trees of the vertex

    Height of the tree:
    Also called depth, is the length of the longest path from the root to one of its leaves

    Levels: in a tree, vertex are classified in levels.
    the level is the number of nodes in the path between the vertex and the root
*/

/*
    Binary tree: each vertex can have two subtrees: subtree at the left and subtree at the right
    the degree of each vertex (number of child) can be: 0, 1, or 2;

    Strict binary tree: each node (vertex) has 0 or 2 subtrees;
    neither node has only one child
    Intern nodes (not leaves) always has 2 child

    Complete binary tree: it is strict binary and all of its leaves are on the same level
    the number of nodes in a complete binary tree is (2^h)-1, where h is height

    Almost complete binary tree: the height difference among the subtrees of any node is at least 1
    If the height of the tree is D, each leaf node is in the level D or D-1

    The binary tree can be implemented using heap or linked list
    where using the heap, static allocation, to return the index of the children
    left of parent is: 2 * parent + 1;
    right of parent is: 2 * parent + 2;

    linked list: has two pointers one to the left and another to the right

*/

struct Vertex {    // or node
    int number;    // This tree will store integer numbers
    Vertex* left;  // Pointer to left child
    Vertex* right; // Pointer to right child
};

typedef Vertex* BinaryTree; // Pointer to vertex

// Create and destroying the tree
BinaryTree* create_tree(); // Creates the root of the tree, will points to the first element of the tree
void free_node(Vertex* v); // This function is used to delete the all the nodes
void delete_tree(BinaryTree* bt); // Destroying the tree

// Access informations
int isEmpty(BinaryTree *bt);
int nodeNumbers(BinaryTree *bt);
int tree_height(BinaryTree *bt);

// Iterate a binary tree, most important, pre, in and post order.

// Pre-order: visit the root, left child and right child
void pre_order(BinaryTree *bt);
// In-order: visit the left child, root, right child
void in_order(BinaryTree *bt);
// post-order: visit the left child, right child and then, root.
void post_order(BinaryTree *bt);

// Inserting elements with the help of a queue
int inserting(BinaryTree *bt, int number);
// Deletion a element in a binary tree
void delete_node(BinaryTree *bt, int number);
void delete_deepest(BinaryTree *bt, Vertex* v);
#endif // BINARY_TREE_H
