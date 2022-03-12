/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
      if(!head)
        return NULL;
      vector<Node*> nodes, newNodes;
      Node *result = NULL, *temp = head, *resultTemp = result;
      map<Node*,int> nodeVsPosition;
      int ind = 0;
      while(temp)
      {
        if(!resultTemp)
        {
          resultTemp = new Node(temp->val);
          result = resultTemp;
        }
        else
        {
          resultTemp->next = new Node(temp->val);
          resultTemp = resultTemp->next;
        }
        
        newNodes.push_back(resultTemp);
        nodeVsPosition[temp] = ind++;
        
        temp = temp->next;
      }
      temp = head;
      resultTemp = result;
      while(temp)
      {
        if(temp->random)
        {
          resultTemp->random = newNodes[nodeVsPosition[temp->random]];
        }
        temp = temp->next;
        resultTemp = resultTemp->next;
      }
      return result;
    }
};