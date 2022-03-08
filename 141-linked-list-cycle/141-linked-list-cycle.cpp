// floyd's cycle detection

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
  bool hasCycle(ListNode *head) {
    if(head == NULL || head->next == NULL)
      return false;
    ListNode *hare = head->next, *tortoise = head;
    while(hare != NULL && hare->next != NULL)
    {
      hare = hare->next->next;
      tortoise = tortoise->next;
      if(hare == tortoise)
        return true;
    }
    return false;
  }
};