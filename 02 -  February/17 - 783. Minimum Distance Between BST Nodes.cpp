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
    int minDiffInBST(TreeNode* root) {
       int ans = INT_MAX;
       vector < int > build;
        auto dfs = [&](auto dfs, TreeNode* root) -> void {
            if(!root) return;
            build.push_back(root->val);
            dfs(dfs, root->left);
            dfs(dfs, root->right);
        };
        dfs(dfs, root);
        sort(build.begin(), build.end());
        for(int i = 1; i < build.size(); i++)
            ans = min(ans, build[i] - build[i - 1]);
        return ans; 
    }
};