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
  int pseudoPalindromicPaths (TreeNode* root, vector<int> &freq) {
    if(root == NULL)
      return 0;
    if(root->left == NULL && root->right == NULL)
    {
      int oddCount = 0;
      freq[root->val]++;
      for(int i=1;i<=9;i++)
      {
        oddCount += freq[i]%2;
      }
      freq[root->val]--;
      return oddCount <= 1;
    }
    freq[root->val]++;
    int leftCount = pseudoPalindromicPaths(root->left, freq);
    int rightCount = pseudoPalindromicPaths(root->right, freq);
    freq[root->val]--;
    return leftCount+rightCount;
  }

  int pseudoPalindromicPaths (TreeNode* root) {
    vector<int> freq(10, 0);
    return pseudoPalindromicPaths(root, freq);
  }
};