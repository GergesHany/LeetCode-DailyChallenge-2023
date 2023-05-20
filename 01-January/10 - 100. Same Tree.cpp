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
    bool isSameTree(TreeNode* p, TreeNode* q) {
      if (!p && !q) return true; // if both are null return true
      else if (!p or !q) return false; // if one of them is null and the other is not return false
      if (p -> val != q -> val) return false; // if the values are not equal return false
      // if the values are equal check the left and right subtrees
      return isSameTree(p -> right, q -> right) && isSameTree(p -> left, q -> left);
    }
};
