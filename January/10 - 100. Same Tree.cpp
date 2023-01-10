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
    // push back in the vector the value of the node
    void build(vector < int >& vec, TreeNode* p){
      if (!p) {
        // if the node is null push back 0
        vec.push_back(0);
        return;
      }
      // push back the value of the node
      vec.push_back(p->val);
      // call the function for the left and right child
      build(vec, p -> right);
      build(vec, p -> left);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
      vector < int > vec1, vec2;
      build(vec1, p); 
      build(vec2, q);
      return vec1 == vec2;
    }
};