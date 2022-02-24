/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

void printLinkedList(ListNode* head)
{
  while(head!=NULL){
    cout<<head->val<<" ";
    head=head->next;
  }
  cout<<"\n";
}

class Solution {
public:
  ListNode* sortList(ListNode* head) {
    if(head == NULL || head->next==NULL)
      return head;
    ListNode* it = head;
    int prevVal = it->val;
    ListNode* prev = it;
    while(it!=NULL)
    {
      while(it!=NULL && it->val>=prevVal){
        prevVal = it->val;
        prev=it;
        it=it->next;
      }
      if(it == NULL)
        break;
      
      ListNode* moveNode = it;
      prev->next=moveNode->next;
      it=it->next;
      if(moveNode->val<=head->val)
      {
        moveNode->next=head;
        head=moveNode;
      }
      else
      {
        ListNode* leftNode=head;
        ListNode* rightNode = leftNode->next;
        while(rightNode!=NULL && moveNode->val>rightNode->val)
        {
          leftNode=rightNode;
          rightNode=rightNode->next;
        }
        leftNode->next = moveNode;
        moveNode->next = rightNode;
      }
      if(it==NULL)
        break;
    }
  // printLinkedList(head);
  return head;
  }
};

/*
1 2 3 4 - sorted

1 2 4 3

*/