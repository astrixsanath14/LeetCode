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

int reverseInOrderTraversal(TreeNode* root, int sum)
{
  if(root == NULL)
    return sum;
  int right = reverseInOrderTraversal(root->right, sum);
  root->val += right;
  int left = reverseInOrderTraversal(root->left, root->val);
  return left;
}

class Solution {
public:
  TreeNode* bstToGst(TreeNode* root) {
    reverseInOrderTraversal(root, 0);
    return root;
  }
};