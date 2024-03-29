/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       map<ListNode*, bool> mp;
      while(true)
      {
        if(head==NULL)
        {
          return NULL;
        }
        if(mp[head])
        {
          return head;
        }
        else
        {
          mp[head] = true; 
        }
        head=head->next;
      }
      return NULL;
    }
};