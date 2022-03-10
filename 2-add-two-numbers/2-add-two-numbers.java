/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
  int carry = 0;
  public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    if(l1!=null && l2!=null){
      l1.val = l1.val + l2.val;
    }
    else if(l2!=null){
      l1 = l2;
      l2 = null;
    }
    if(l1!=null)
    {
      l1.val += carry;
      carry = l1.val/10;
      l1.val %= 10;
      l1.next = addTwoNumbers(l1.next, l2 !=null ? l2.next : null);
      return l1;
    }
    if(carry!=0)
      return new ListNode(1);
    
    return null;
  }
}