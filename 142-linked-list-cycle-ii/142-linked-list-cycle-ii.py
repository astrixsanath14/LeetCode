# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution():
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        cycleNode = None
        hare = head
        tortoise = head
        if hare == None:
          return None
        while True:
          hare = hare.next
          if hare == None:
            return None
          hare = hare.next
          if hare == None:
            return None
          tortoise = tortoise.next
          if hare == tortoise:
            cycleNode = hare
            break
        temp = head
        while temp != cycleNode:
          temp = temp.next
          cycleNode = cycleNode.next
        return cycleNode