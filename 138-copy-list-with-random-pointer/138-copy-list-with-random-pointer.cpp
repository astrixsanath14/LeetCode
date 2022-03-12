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
      Node *result = new Node(-1), *temp = head, *resultTemp = result;
      map<Node*,Node*> nodeVsCopiedNode;
      int ind = 0;
      while(temp)
      {
        resultTemp->next = new Node(temp->val);
        resultTemp = resultTemp->next;
        nodeVsCopiedNode[temp] = resultTemp;
                
        temp = temp->next;
      }
      temp = head;
      resultTemp = result->next;
      while(temp)
      {
        if(temp->random)
        {
          resultTemp->random = nodeVsCopiedNode[temp->random];
        }
        temp = temp->next;
        resultTemp = resultTemp->next;
      }
      return result->next;
    }
};