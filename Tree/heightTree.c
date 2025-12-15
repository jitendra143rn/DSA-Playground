/*
GFG-160
Height of Binary Tree

Given the root of a binary tree, your task is to find the maximum depth of the tree.
Note: The maximum depth or height of the tree is the number of edges in the tree from the root to the deepest node.

*/

class Solution {
  public:
    int height(Node* root) {
        int x, y ;
        if(root == NULL)
        {
            return -1; 
        }   
        x = height(root->left);
        y = height(root->right);
        ///return 1 + max(x, y);
        return 1 + (x > y ? x : y);
  
    }
};
