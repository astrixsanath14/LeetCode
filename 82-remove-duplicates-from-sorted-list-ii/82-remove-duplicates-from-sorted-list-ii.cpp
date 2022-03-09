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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode *slowPointer = head, *prev = NULL;
    while(slowPointer != NULL)
    {
      ListNode* fastPointer = slowPointer->next;
      while(fastPointer!= NULL && fastPointer->val == slowPointer->val)
        fastPointer=fastPointer->next;
      if(fastPointer == slowPointer->next){
        if(prev == NULL){
          prev = slowPointer;
          head = slowPointer;
        }
        else
        {
          prev->next = slowPointer;
          prev = prev->next;
        }
      }
      else
      {
        if(prev == NULL)
          head = fastPointer;
        else
          prev->next = NULL;
      }
      slowPointer = fastPointer;
    }
    return head;
  }
};