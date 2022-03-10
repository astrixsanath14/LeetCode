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
  int carry = 0;
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // int c = 0;
    // ListNode newHead(0);
    // ListNode *t = &newHead;
    // while(c || l1 || l2) {
    //     c += (l1? l1->val : 0) + (l2? l2->val : 0);
    //     t->next = new ListNode(c%10);
    //     t = t->next;
    //     c /= 10;
    //     if(l1) l1 = l1->next;
    //     if(l2) l2 = l2->next;
    // }
    // return newHead.next;
    
    if(l1 && l2){
      l1->val = l1->val + l2->val;
    }
    else if(l2){
      l1 = l2;
      l2 = NULL;
    }
    if(l1)
    {
      l1->val += carry;
      carry = l1->val/10;
      l1->val %= 10;
      l1->next = addTwoNumbers(l1->next, l2 ? l2->next : NULL);
      return l1;
    }
    if(carry)
      return new ListNode(1);
    
    return NULL;
  }
};