struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        vector < TreeNode* > ans; // answer vector
        
        unordered_map < string, int > mp; // map to store the frequency of each subtree
        // string is the preorder traversal of the subtree
        function < string(TreeNode*) > dfs = [&](TreeNode* node){
            if (!node) return string("#"); // if the node is null return # to represent null
            // return the preorder traversal of the subtree
            string s = to_string(node->val) + "," + dfs(node->left) + "," + dfs(node->right);
            if (mp[s] == 1) ans.push_back(node); // if the frequency of the subtree is 1 then it is a duplicate subtree 
            mp[s]++; // increase the frequency of the subtree
            return s; // return the preorder traversal of the subtree
        };

        dfs(root); // call the dfs function

        return ans; // return the answer vector
    }
};
