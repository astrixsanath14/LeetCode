void getTreeElements(TreeNode* root, vector<int>& elements)
{
  if(root == NULL)
  {
    return;
  }
  int nodeVal = root->val;
  getTreeElements(root->left, elements);
  elements.push_back(nodeVal);
  getTreeElements(root->right, elements);
}

void printVectorContents(vector<int>& arr)
{
  for(int val: arr)
  {
    cout<<val<<" ";
  }
  cout<<endl;
}

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
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
  {
    TreeNode* temp1 = root1;
    TreeNode* temp2 = root2;
    vector<int> tree1Nodes;
    vector<int> tree2Nodes;
    getTreeElements(root1, tree1Nodes);
    printVectorContents(tree1Nodes);
    getTreeElements(root2, tree2Nodes);
    printVectorContents(tree2Nodes);
    int size1 = tree1Nodes.size(), size2 = tree2Nodes.size();
    int minSize = size1 < size2 ? size1 : size2;
    vector<int> resultElements(size1+size2);
    int ii=0,jj=0,i=0;
    while(true)
    {
      if(ii==size1 || jj==size2)
        break;
      if(tree1Nodes[ii] < tree2Nodes[jj])
      {
        resultElements[i++] = tree1Nodes[ii++];
      }
      else if(tree1Nodes[ii] > tree2Nodes[jj])
      {
        resultElements[i++] = tree2Nodes[jj++];
      }
      else
      {
        resultElements[i++] = tree1Nodes[ii++];
        resultElements[i++] = tree2Nodes[jj++];
      }
    }
    while(ii<size1)
    {
      resultElements[i++] = tree1Nodes[ii++];
    }
    while(jj<size2)
    {
      resultElements[i++] = tree2Nodes[jj++];
    }
    return resultElements;
  }
};