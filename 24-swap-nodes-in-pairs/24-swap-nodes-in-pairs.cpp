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
  
public:
  ListNode* swapPairs(ListNode* curr, ListNode* prev) {
    if(curr == NULL)
      return curr;
    ListNode* temp = curr->next;
    if(temp == NULL)
      return curr;
    curr->next = temp->next;
    temp->next = curr;
    if(prev != NULL)
      prev->next = temp;
    swapPairs(curr->next, curr);
    return temp;
  }
  ListNode* swapPairs(ListNode* head) {
    return swapPairs(head, NULL);
  }
};