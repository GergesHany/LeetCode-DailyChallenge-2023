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
    void reverse(TreeNode* root){
        if (!root) return;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        reverse(root->left);
        reverse(root->right);
    }

    bool is_same(TreeNode* root1, TreeNode* root2){
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        if (root1->val != root2->val) return false;
        return is_same(root1->left, root2->left) && is_same(root1->right, root2->right);
    }
   
    bool isSymmetric(TreeNode* root) {
        if (!root) return false;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        reverse(right);
        return is_same(left, right);
    }
}; 