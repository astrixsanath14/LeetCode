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
  vector<int> rightSideView(TreeNode* root) {
    vector<int> rightSideViews;
    queue<TreeNode*> nodes;
      if(root != NULL)
        nodes.push(root);
    while(!nodes.empty())
    {
      int size = nodes.size();
      for(int i=0;i<size;i++)
      {
        TreeNode* node = nodes.front();
        if(node->left)
          nodes.push(node->left);
        if(node->right)
          nodes.push(node->right);
        if(i == size-1)
          rightSideViews.push_back(node->val);
        nodes.pop();
      }
    }
    return rightSideViews;
  }
};