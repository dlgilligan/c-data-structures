#include <stdlib.h>
#include <stdio.h>

// A level of a binary tree l, has a maximum of 2^l nodes
// A level is the number of steps a node is away from the root
// Root being level 0, with 2^0 = 1 nodes

// The maximum number of nodes in a tree of height l is (2^l) - 1
// Height of a tree is the maximum number of nodes on a path from root to leaf
// Height of a tree with a sinngle node is 1

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) {
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new -> data = data;
    new -> left = NULL;
    new -> right = NULL;

    return new;
}

int max(int a, int b) { return (a > b) ? a : b; }

int height(struct node* tree) {
    if(tree == null) { return 0; }

    return 1 + max(height(tree -> left),height(tree -> right));

}

int diameter(struct node* tree) {
    if(tree == NULL) { return 0; }


    int lheight = height(tree -> left);
    int rheight = height(tree -> right);

    int ldiameter = diameter(tree -> left);
    int rdiameter = diameter(tree -> right);

    return max(lheight + rheight, max(ldiameter,rdiameter));
}



