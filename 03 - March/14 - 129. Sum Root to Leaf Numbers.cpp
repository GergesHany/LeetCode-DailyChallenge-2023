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
    
   long long ans = 0;
   void get_ans(TreeNode* root, long long build){
     if (!root) return;
      build = build * 10 + root->val;
      if (!root->left && !root->right) ans += build;
      get_ans(root->left, build);
      get_ans(root->right, build);
   } 

    int sumNumbers(TreeNode* root) {
      get_ans(root, 0);
      return ans;  
    }
};