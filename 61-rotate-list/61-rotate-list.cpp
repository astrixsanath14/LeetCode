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
class Solution {
public:
  ListNode* rotateRight(ListNode* head, int k) {
    if(!head || !head->next)
      return head;
    int n = 1;
    ListNode *end = head, *temp = head;
    while(end->next)
      end = end->next,n++;
    k%=n;
    for(int i=0;i<n-k-1;i++)
      temp=temp->next;
    
    end->next = head;
    head = temp->next;
    temp->next = NULL;
    
    return head;
  }
};