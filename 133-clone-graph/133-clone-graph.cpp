/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
      if(node == NULL)
        return NULL;
      unordered_map<int,Node*> nodeValVsNodeMap;
      unordered_map<int,bool> visitedNode;
      queue<Node*> remainingQ;
      remainingQ.push(node);
      while(!remainingQ.empty())
      {
        int q = remainingQ.size();
        while(q--)
        {
          Node* currNode = remainingQ.front();
          remainingQ.pop();
          Node* currNewNode;
          if(nodeValVsNodeMap.count(currNode->val)==0)
          {
            currNewNode = new Node(currNode->val);
            nodeValVsNodeMap[currNewNode->val] = currNewNode;
          }
          else
          {
            currNewNode = nodeValVsNodeMap[currNode->val];
          }
          for(Node* adjNode:currNode->neighbors)
          {
            Node* newAdjNode;
            if(nodeValVsNodeMap.count(adjNode->val) == 0)
            {
              newAdjNode = new Node(adjNode->val);
              nodeValVsNodeMap[newAdjNode->val] = newAdjNode;
            }
            else
            {
              newAdjNode = nodeValVsNodeMap[adjNode->val];
            }
            if(find(currNewNode->neighbors.begin(), currNewNode->neighbors.end(), newAdjNode)==currNewNode->neighbors.end())
              currNewNode->neighbors.push_back(newAdjNode);
            // newAdjNode->neighbors.push_back(currNewNode);
            if(!visitedNode[adjNode->val])
            {
              remainingQ.push(adjNode);
            }
          }
          visitedNode[currNode->val] = true;
        }
      }
      return nodeValVsNodeMap[1];
    }
};