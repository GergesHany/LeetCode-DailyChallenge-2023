
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
#define sz(s) int(s.size())
#define all(s) s.begin(), s.end()
public:
    // function to do dfs and push the nodes in the vector
    void dfs(TreeNode* root, int level, vector < vector < int > > &ans){
      if (!root) return; // if the node is null return
      if (sz(ans) == level) ans.push_back({}); // if the level is not in the vector push it
      ans[level].push_back(root->val); // push the node in the vector
      dfs(root->left, level + 1, ans); // do dfs in the left subtree
      dfs(root->right, level + 1, ans); // do dfs in the right subtree
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector < vector < int > > ans; // vector to store the answer
      if (!root) return ans; // if the root is null return the vector
      dfs(root, 0, ans); // do dfs and push the nodes in the vector
      // reverse the odd levels in the vector to get the zigzag order
      for (int i = 1; i < sz(ans); i += 2) 
        reverse(all(ans[i])); 
      return ans;  // return the vector 
    }
};