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
    bool isComplete(TreeNode* root, int index, int n){
        if(!root) return true;
        if(index >= n) return false;
        return isComplete(root->left, 2 * index + 1, n) && isComplete(root->right, 2 * index + 2, n);
    }
    bool isCompleteTree(TreeNode* root) {
        int n = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node){
                n++;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return isComplete(root, 0, n);
    }
};