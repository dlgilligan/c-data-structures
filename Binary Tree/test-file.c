#include "binary-tree-funcs.h"

int main () {
    struct node* root = newNode(1);

    root -> left = newNode(2);
    root -> right = newNode(3);

    root -> left -> left = newNode(4);

    //Creates a binary tree depicted in the diagram below
    /*
            1
          /   \
         2     3
        / \   / \
       4   N  N  NULL
    */

   // A level of a binary tree l, has a maximum of 2^l nodes
   // A level is the number of steps a node is away from the root
   // Root being level 0, with 2^0 = 1 nodes

   // The maximum number of nodes in a tree of height l is (2^l) - 1
   // Height of a tree is the maximum number of nodes on a path from root to leaf
   // Height of a tree with a sinngle node is 1

   
}