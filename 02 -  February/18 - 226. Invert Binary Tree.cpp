/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL; // base case
        TreeNode* left = invertTree(root->left); // invert left subtree
        TreeNode* right = invertTree(root->right); // invert right subtree
        root->left = right; // swap left and right subtrees
        root->right = left; // swap left and right subtrees
        return root;
    }
};
