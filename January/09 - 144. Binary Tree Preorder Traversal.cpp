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
   vector < int > ans;
   // preorder function 
   void preorder(TreeNode* root){
        if (!root) return;
        // first push the root value in the vector
        ans.push_back(root -> val);
        // now recur on left subtree         
        preorder(root -> left);
        // now recur on right subtree
        preorder(root -> right); 
    }
    vector<int> preorderTraversal(TreeNode* root) {
      preorder(root);
      return ans;
    }
};
