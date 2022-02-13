class Node
{
  public:
  long long nodeVal;
  long noOfChildren;
  Node* left;
  Node* right;
  Node* parent;
  Node(int val)
  {
    nodeVal = val;
    left = NULL;
    right = NULL;
    parent= NULL;
    noOfChildren = 0;
  }
};

int calculateAndUpdateNoOfChildren(Node* node)
{
  if(node == NULL)
  {
    return 0;
  }
  int noOfChildren = calculateAndUpdateNoOfChildren(node->left) + calculateAndUpdateNoOfChildren(node->right);
  node->noOfChildren = noOfChildren;
  return noOfChildren+1;
}

class Solution {
public:
  int countHighestScoreNodes(vector<int>& parents) {
    int noOfNodes = parents.size();
    vector<Node*> tree(noOfNodes);
    for(int i=0;i<noOfNodes;i++)
    {
      tree[i] = new Node(i);
    }
    for(int i=1;i<noOfNodes;i++)
    {
      Node* curParent = tree[parents[i]];
      Node* curChild = tree[i];
      if(curParent->left == NULL)
      {
        curParent->left = curChild;
      }
      else
      {
        curParent->right = curChild;
      }
      curChild->parent = curParent;
    }
    calculateAndUpdateNoOfChildren(tree[0]);
    // for(int i=0;i<noOfNodes;i++)
    // {
    //   cout<<i<<" "<<tree[i]->noOfChildren<<"\n";
    // }
    long long maxVal = INT_MIN, maxCountNoOfNodes = 0;
    
    for(int i=0;i<noOfNodes;i++)
    {
      long long leftCount = 0;
      long long rightCount = 0;
      if(tree[i]->left!=NULL)
        leftCount = tree[i]->left->noOfChildren + 1;
      if(tree[i]->right!=NULL)
        rightCount = tree[i]->right->noOfChildren + 1;
      
      long long remaining = noOfNodes - leftCount - rightCount-1;
      leftCount = max(leftCount, (long long)1);
      rightCount = max(rightCount, (long long)1);
      remaining = max(remaining, (long long)1);
      long long val = remaining * leftCount * rightCount;
      // cout<<i<<" "<<remaining<<" "<<leftCount<<" "<<rightCount<<" "<<val<<"\n";
      if(maxVal < val)
      {
        maxVal = val;
        maxCountNoOfNodes = 1;
      }
      else if(maxVal == val)
      {
        maxCountNoOfNodes++;
      }
    }
    return maxCountNoOfNodes;
  }
};