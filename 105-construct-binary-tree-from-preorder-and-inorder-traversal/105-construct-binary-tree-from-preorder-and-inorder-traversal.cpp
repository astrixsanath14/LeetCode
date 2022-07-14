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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int rootInd = 0, left = 0, right = inorder.size()-1;
    return buildTree(preorder, inorder, rootInd, left, right);
  }
  
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int& rootInd, int leftInd, int rightInd) {
    if(leftInd > rightInd)
      return NULL;
    int inorderInd = leftInd;
    while(inorder[inorderInd] != preorder[rootInd])
      inorderInd++;
    TreeNode* node = new TreeNode(preorder[rootInd]);
    rootInd++;
    node->left = buildTree(preorder, inorder, rootInd, leftInd, inorderInd-1);
    node->right = buildTree(preorder, inorder, rootInd, inorderInd+1, rightInd);
    return node;
  }
};